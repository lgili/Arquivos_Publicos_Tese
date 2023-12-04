void correntes(int line,double Ia,double Ib,double Ic,double Iu,double Iv,double Iw, double *cx1, double *cx2, double *cx3, double *cx4, double *cx5, double *cx6, double *cx7,double *cx8,double *cx9)
{
	switch (line)
	{
    case 0:

            *cx1=Ia;
            *cx2=0;
            *cx3=0;
            *cx4=Ib;
            *cx5=0;
            *cx6=0;
            *cx7=-Ia-Ib-Iu;
            *cx8=-Iv;
            *cx9=-Iw;
         break;

    case 1:

        *cx1=Ia;
        *cx2=0;
        *cx3=0;
        *cx4=0;
        *cx5=Ib;
        *cx6=0;
        *cx7=-Ia-Iu;
        *cx8=-Ib-Iv;
        *cx9=-Iw;
     break;

    case 2:

        *cx1=Ia;
        *cx2=0;
        *cx3=0;
        *cx4=0;
        *cx5=0;
        *cx6=Ib;
        *cx7=-Ia-Iu;
        *cx8=-Iv;
        *cx9=-Ib-Iw;
     break;

    case 3:

        *cx1=0;
        *cx2=Ia;
        *cx3=0;
        *cx4=Ib;
        *cx5=0;
        *cx6=0;
        *cx7=-Ib-Iu;
        *cx8=-Ia-Iv;
        *cx9=-Iw;
     break;

    case 4:

        *cx1=0;
        *cx2=Ia;
        *cx3=0;
        *cx4=0;
        *cx5=Ib;
        *cx6=0;
        *cx7=-Iu;
        *cx8=-Ia-Ib-Iv;
        *cx9=-Iw;
     break;

    case 5:

        *cx1=0;
        *cx2=Ia;
        *cx3=0;
        *cx4=0;
        *cx5=0;
        *cx6=Ib;
        *cx7=-Iu;
        *cx8=-Ia-Iv;
        *cx9=-Ib-Iw;
     break;

    case 6:

        *cx1=0;
        *cx2=0;
        *cx3=Ia;
        *cx4=Ib;
        *cx5=0;
        *cx6=0;
        *cx7=-Ib-Iu;
        *cx8=-Iv;
        *cx9=-Ia-Iw;
     break;

    case 7:

        *cx1=0;
        *cx2=0;
        *cx3=Ia;
        *cx4=0;
        *cx5=Ib;
        *cx6=0;
        *cx7=-Iu;
        *cx8=-Ib-Iv;
        *cx9=-Ia-Iw;
     break;

    case 8:

        *cx1=0;
        *cx2=0;
        *cx3=Ia;
        *cx4=0;
        *cx5=0;
        *cx6=Ib;
        *cx7=-Iu;
        *cx8=-Iv;
        *cx9=-Ia-Ib-Iw;
     break;


     case 9:

        *cx1=Ia;
        *cx2=0;
        *cx3=0;
        *cx4=Ib+Iv;
        *cx5=-Iv;
        *cx6=0;
        *cx7=-Ia-Ib-Iu-Iv;
        *cx8=0;
        *cx9=-Iw;
     break;

    case 10:

        *cx1=Ia;
        *cx2=0;
        *cx3=0;
        *cx4=-Ia-Iu;
        *cx5=Ia+Ib+Iu;
        *cx6=0;
        *cx7=0;
        *cx8=-Ia-Ib-Iu-Iv;
        *cx9=-Iw;
     break;

    case 11:

        *cx1=Ia;
        *cx2=0;
        *cx3=0;
        *cx4=Ib+Iw;
        *cx5=0;
        *cx6=-Iw;
        *cx7=-Ia-Ib-Iu-Iw;
        *cx8=-Iv;
        *cx9=0;
     break;
    case 12:

        *cx1=Ia;
        *cx2=0;
        *cx3=0;
        *cx4=-Ia-Iu;
        *cx5=0;
        *cx6=Ia+Ib+Iu;
        *cx7=0;
        *cx8=-Iv;
        *cx9=-Ia-Ib-Iu-Iw;
      break;

    case 13:

        *cx1=Ia;
        *cx2=0;
        *cx3=0;
        *cx4=0;
        *cx5=Ib+Iw;
        *cx6=-Iw;
        *cx7=-Ia-Iu;
        *cx8=-Ib-Iv-Iw;
        *cx9=0;
     break;

    case 14:

        *cx1=Ia;
        *cx2=0;
        *cx3=0;
        *cx4=0;
        *cx5=-Iv;
        *cx6=Ib+Iv;
        *cx7=-Ia-Iu;
        *cx8=0;
        *cx9=-Ib-Iv-Iw;
     break;

    case 15:

        *cx1=0;
        *cx2=Ia;
        *cx3=0;
        *cx4=Ia+Ib+Iv;
        *cx5=-Ia-Iv;
        *cx6=0;
        *cx7=-Ia-Ib-Iu-Iv;
        *cx8=0;
        *cx9=-Iw;
     break;

    case 16:

        *cx1=0;
        *cx2=Ia;
        *cx3=0;
        *cx4=-Iu;
        *cx5=Ib+Iu;
        *cx6=0;
        *cx7=0;
        *cx8=-Ia-Ib-Iu-Iv;
        *cx9=-Iw;
     break;

    case 17:

        *cx1=0;
        *cx2=Ia;
        *cx3=0;
        *cx4=Ib+Iw;
        *cx5=0;
        *cx6=-Iw;
        *cx7=-Ib-Iu-Iw;
        *cx8=-Ia-Iv;
        *cx9=0;
     break;

    case 18:

        *cx1=0;
        *cx2=Ia;
        *cx3=0;
        *cx4=-Iu;
        *cx5=0;
        *cx6=Ib+Iu;
        *cx7=0;
        *cx8=-Ia-Iv;
        *cx9=Ib-Iu-Iw;
     break;

    case 19:

        *cx1=0;
        *cx2=Ia;
        *cx3=0;
        *cx4=0;
        *cx5=Ib+Iw;
        *cx6=-Iw;
        *cx7=-Iu;
        *cx8=-Ia-Ib-Iv-Iw;
        *cx9=0;
     break;

    case 20:

        *cx1=0;
        *cx2=Ia;
        *cx3=0;
        *cx4=0;
        *cx5=-Ia-Iv;
        *cx6=Ia+Ib+Iv;
        *cx7=-Iu;
        *cx8=0;
        *cx9=-Ia-Ib-Iv-Iw;
     break;

     case 21:

        *cx1=0;
        *cx2=0;
        *cx3=Ia;
        *cx4=Ib+Iv;
        *cx5=-Iv;
        *cx6=0;
        *cx7=-Ib-Iu-Iv;
        *cx8=0;
        *cx9=-Ia-Iw;
     break;

    case 22:

        *cx1=0;
        *cx2=0;
        *cx3=Ia;
        *cx4=-Iu;
        *cx5=Ib+Iu;
        *cx6=0;
        *cx7=0;
        *cx8=-Ib-Iu-Iv;
        *cx9=-Ia-Iw;
     break;

    case 23:

        *cx1=0;
        *cx2=0;
        *cx3=Ia;
        *cx4=Ia+Ib+Iw;
        *cx5=0;
        *cx6=-Ia-Iw;
        *cx7=-Ia-Ib-Iu-Iw;
        *cx8=-Iv;
        *cx9=0;
     break;

    case 24:

        *cx1=0;
        *cx2=0;
        *cx3=Ia;
        *cx4=-Iu;
        *cx5=0;
        *cx6=Ib+Iu;
        *cx7=0;
        *cx8=-Iv;
        *cx9=-Ia-Ib-Iu-Iw;
         break;
    case 25:

        *cx1=0;
        *cx2=0;
        *cx3=Ia;
        *cx4=0;
        *cx5=Ia+Ib+Iw;
        *cx6=-Ia-Iw;
        *cx7=-Iu;
        *cx8=-Ia-Ib-Iv-Iw;
        *cx9=0;
         break;
    case 26:

        *cx1=0;
        *cx2=0;
        *cx3=Ia;
        *cx4=0;
        *cx5=-Iv;
        *cx6=Ib+Iv;
        *cx7=-Iu;
        *cx8=0;
        *cx9=-Ia-Ib-Iv-Iw;
         break;
    case 27:

        *cx1=Ia;
        *cx2=0;
        *cx3=0;
        *cx4=Ib+Iv+Iw;
        *cx5=-Iv;
        *cx6=-Iw;
        *cx7=-Ia-Ib-Iu-Iv-Iw;
        *cx8=0;
        *cx9=0;
         break;
    case 28:

        *cx1=Ia;
        *cx2=0;
        *cx3=0;
        *cx4=-Ia-Iu;
        *cx5=Ia+Ib+Iu+Iw;
        *cx6=-Iw;
        *cx7=0;
        *cx8=-Ia-Ib-Iu-Iv-Iw;
        *cx9=0;
         break;
    case 29:

        *cx1=Ia;
        *cx2=0;
        *cx3=0;
        *cx4=-Ia-Iu;
        *cx5=-Iv;
        *cx6=Ia+Ib+Iu+Iv;
        *cx7=0;
        *cx8=0;
        *cx9=-Ia-Ib-Iu-Iv-Iw;
         break;
    case 30:

        *cx1=0;
        *cx2=Ia;
        *cx3=0;
        *cx4=Ia+Ib+Iv+Iw;
        *cx5=-Ia-Iv;
        *cx6=-Iw;
        *cx7=-Ia-Ib-Iu-Iv-Iw;
        *cx8=0;
        *cx9=0;
         break;
      case 31:

        *cx1=0;
        *cx2=Ia;
        *cx3=0;
        *cx4=-Iu;
        *cx5=Ib+Iu+Iw;
        *cx6=-Iw;
        *cx7=0;
        *cx8=-Ia-Ib-Iu-Iv-Iw;
        *cx9=0;
         break;
    case 32:

        *cx1=0;
        *cx2=Ia;
        *cx3=0;
        *cx4=-Iu;
        *cx5=-Ia-Iv;
        *cx6=Ia+Ib+Iu+Iv;
        *cx7=0;
        *cx8=0;
        *cx9=-Ia-Ib-Iu-Iv-Iw;
         break;
    case 33:

        *cx1=0;
        *cx2=0;
        *cx3=Ia;
        *cx4=Ia+Ib+Iv+Iw;
        *cx5=-Iv;
        *cx6=-Ia-Iw;
        *cx7=-Ia-Ib-Iu-Iv-Iw;
        *cx8=0;
        *cx9=0;
         break;
    case 34:

        *cx1=0;
        *cx2=0;
        *cx3=Ia;
        *cx4=-Iu;
        *cx5=Ia+Ib+Iu+Iw;
        *cx6=-Ia-Iw;
        *cx7=0;
        *cx8=-Ia-Ib-Iu-Iv-Iw;
        *cx9=0;
         break;
    case 35:

        *cx1=0;
        *cx2=0;
        *cx3=Ia;
        *cx4=-Iu;
        *cx5=-Iv;
        *cx6=Ib+Iu+Iv;
        *cx7=0;
        *cx8=0;
        *cx9=-Ia-Ib-Iu-Iv-Iw;
         break;
    case 36:

        *cx1=Ia+Iv;
        *cx2=-Iv;
        *cx3=0;
        *cx4=Ib;
        *cx5=0;
        *cx6=0;
        *cx7=-Ia-Ib-Iu-Iv;
        *cx8=0;
        *cx9=-Iw;
         break;
    case 37:

        *cx1=-Ib-Iu;
        *cx2=Ia+Ib+Iu;
        *cx3=0;
        *cx4=Ib;
        *cx5=0;
        *cx6=0;
        *cx7=0;
        *cx8=-Ia-Ib-Iu-Iv;
        *cx9=-Iw;
         break;
    case 38:

        *cx1=Ia+Ib+Iv;
        *cx2=-Ib-Iv;
        *cx3=0;
        *cx4=0;
        *cx5=Ib;
        *cx6=0;
        *cx7=-Ia-Ib-Iu-Iv;
        *cx8=0;
        *cx9=-Iw;
         break;
    case 39:

        *cx1=-Iu;
        *cx2= Ia+Iu;
        *cx3=0;
        *cx4=0;
        *cx5=Ib;
        *cx6=0;
        *cx7=0;
        *cx8=-Ia-Ib-Iu-Iv;
        *cx9=-Iw;
         break;
    case 40:

        *cx1=Ia+Iv;
        *cx2=-Iv;
        *cx3=0;
        *cx4=0;
        *cx5=0;
        *cx6=Ib;
        *cx7=-Ia-Iu-Iv;
        *cx8=0;
         break;
     case 41:

        *cx1=-Iu;
        *cx2=Ia+Iu;
        *cx3=0;
        *cx4=0;
        *cx5=0;
        *cx6=-Ia-Iu-Iv;
        *cx7=0;
        *cx8=0;
        *cx9=-Ib-Iw;
         break;
    case 42:

        *cx1=Ia+Iw;
        *cx2=0;
        *cx3=-Iw;
        *cx4=Ib;
        *cx5=0;
        *cx6=0;
        *cx7=-Ia-Ib-Iu-Iw;
        *cx8=-Iv;
        *cx9=0;
         break;
    case 43:

        *cx1=-Ib-Iu;
        *cx2=0;
        *cx3=Ia+Ib+Iu;
        *cx4=Ib;
        *cx5=0;
        *cx6=0;
        *cx7=0;
        *cx8=-Iv;
        *cx9=-Ia-Ib-Iu-Iw;
         break;
    case 44:

        *cx1=Ia+Iw;
        *cx2=0;
        *cx3=-Iw;
        *cx4=0;
        *cx5=Ib;
        *cx6=0;
        *cx7=-Ia-Iu-Iw;
        *cx8=-Ib-Iv;
        *cx9=0;
         break;
    case 45:

        *cx1=-Iu;
        *cx2=0;
        *cx3=Ia+Iu;
        *cx4=0;
        *cx5=Ib;
        *cx6=0;
        *cx7=0;
        *cx8=-Ib-Iv;
        *cx9=-Ia-Iu-Iw;
         break;
    case 46:

        *cx1=Ia+Ib+Iw;
        *cx2=0;
        *cx3=-Ib-Iw;
        *cx4=0;
        *cx5=0;
        *cx6=Ib;
        *cx7=-Ia-Ib-Iu-Iw;
        *cx8=-Iv;
        *cx9=0;
         break;
    case 47:

        *cx1=-Iu;
        *cx2=0;
        *cx3=Ia+Iu;
        *cx4=0;
        *cx5=0;
        *cx6=Ib;
        *cx7=0;
        *cx8=-Iv;
        *cx9=-Ia-Ib-Iu-Iw;
         break;
    case 48:

        *cx1=0;
        *cx2=Ia+Iw;
        *cx3=-Iw;
        *cx4=Ib;
        *cx5=0;
        *cx6=0;
        *cx7=-Ib-Iu;
        *cx8=-Ia-Iv-Iw;
        *cx9=0;
         break;
    case 49:

        *cx1=0;
        *cx2=-Iv;
        *cx3=Ia+Iv;
        *cx4=Ib;
        *cx5=0;
        *cx6=0;
        *cx7=-Ib-Iu;
        *cx8=0;
        *cx9=-Ia-Iv-Iw;
         break;
    case 50:

        *cx1=0;
        *cx2=Ia+Iw;
        *cx3=-Iw;
        *cx4=0;
        *cx5=Ib;
        *cx6=0;
        *cx7=-Iu;
        *cx8=-Ia-Ib-Iv-Iw;
        *cx9=0;
         break;
     case 51:

        *cx1=0;
        *cx2=-Ib-Iv;
        *cx3=Ia+Ib+Iv;
        *cx4=0;
        *cx5=Ib;
        *cx6=0;
        *cx7=-Iu;
        *cx8=0;
        *cx9=-Ia-Ib-Iv-Iw;
         break;
     case 52:

        *cx1=0;
        *cx2=Ia+Ib+Iw;
        *cx3=-Ib-Iw;
        *cx4=0;
        *cx5=0;
        *cx6=Ib;
        *cx7=-Iu;
        *cx8=-Ia-Ib-Iv-Iw;
        *cx9=0;
         break;
    case 53:

        *cx1=0;
        *cx2=-Iv;
        *cx3=Ia+Iv;
        *cx4=0;
        *cx5=0;
        *cx6=Ib;
        *cx7=-Iu;
        *cx8=0;
        *cx9=-Ia-Ib-Iv-Iw;
         break;
    case 54:

        *cx1=Ia+Iv;
        *cx2=-Iv;
        *cx3=0;
        *cx4=Ib+Iw;
        *cx5=0;
        *cx6=-Iw;
        *cx7=-Ia-Ib-Iu-Iv-Iw;
        *cx8=0;
        *cx9=0;
         break;
    case 55:

        *cx1=-Ib-Iu-Iw;
        *cx2=Ia+Ib+Iu+Iw;
        *cx3=0;
        *cx4=Ib+Iw;
        *cx5=0;
        *cx6=-Iw;
        *cx7=0;
        *cx8=-Ia-Ib-Iu-Iv-Iw;
        *cx9=0;
         break;
    case 56:

        *cx1=Ia+Ib;
        *cx2=-Iv;
        *cx3=0;
        *cx4=-Ia-Iu-Iv;
        *cx5=0;
        *cx6=Ia+Ib+Iu+Iv;
        *cx7=0;
        *cx8=0;
        *cx9=-Ia-Ib-Iu-Iv-Iw;
         break;
    case 57:

        *cx1=Ia+Ib+Iv+Iw;
        *cx2=-Ib-Iv-Iw;
        *cx3=0;
        *cx4=0;
        *cx5=Ib+Iw;
        *cx6=-Iw;
        *cx7=-Ia-Ib-Iu-Iv-Iw;
        *cx8=0;
        *cx9=0;
         break;
    case 58:

        *cx1=-Iu;
        *cx2=Ia+Iu;
        *cx3=0;
        *cx4=0;
        *cx5=Ib+Iw;
        *cx6=-Iw;
        *cx7=0;
        *cx8=-Ia-Ib-Iu-Iv-Iw;
        *cx9=0;
         break;
    case 59:

        *cx1=-Iu;
        *cx2=Ia+Iu;
        *cx3=0;
        *cx4=0;
        *cx5=-Ia-Ib-Iv;
        *cx6=Ia+Ib+Iu+Iv;
        *cx7=0;
        *cx8=0;
        *cx9=-Ia-Ib-Iu-Iv-Iw;
         break;
    case 60:

        *cx1=Ia+Iw;
        *cx2=0;
        *cx3=-Iw;
        *cx4=Ib+Iv;
        *cx5=-Iv;
        *cx6=0;
        *cx7=-Ia-Ib-Iu-Iv-Iw;
        *cx8=0;
        *cx9=0;
         break;
     case 61:

        *cx1=Ia+Iw;
        *cx2=0;
        *cx3=-Iw;
        *cx4=-Ia-Iu-Iw;
        *cx5=Ia+Ib+Iu+Iw;
        *cx6=0;
        *cx7=0;
        *cx8=-Ia-Ib-Iu-Iv-Iw;
        *cx9=0;
         break;
    case 62:

        *cx1=-Ib-Iu-Iv;
        *cx2=0;
        *cx3=Ia+Ib+Iu+Iv;
        *cx4=Ib+Iv;
        *cx5=-Iv;
        *cx6=0;
        *cx7=0;
        *cx8=0;
        *cx9=-Ia-Ib-Iu-Iv-Iw;
         break;
    case 63:

        *cx1=Ia+Ib+Iv+Iw;
        *cx2=0;
        *cx3=-Ib-Iv-Iw;
        *cx4=0;
        *cx5=-Iv;
        *cx6=Ib+Iv;
        *cx7=-Ia-Ib-Iu-Iv-Iw;
        *cx8=0;
        *cx9=0;
         break;
    case 64:

        *cx1=-Iu;
        *cx2=0;
        *cx3=Ia+Iu;
        *cx4=0;
        *cx5=Ia+Ib+Iu+Iw;
        *cx6=0;
        *cx7=-Ia-Iu-Iw;
        *cx8=-Ia-Ib-Iu-Iv-Iw;
        *cx9=0;
         break;
    case 65:

        *cx1=-Iu;
        *cx2=0;
        *cx3=Ia+Iu;
        *cx4=0;
        *cx5=-Iv;
        *cx6=Ib+Iv;
        *cx7=0;
        *cx8=0;
        *cx9=-Ia-Ib-Iu-Iv-Iw;
         break;
    case 66:

        *cx1=0;
        *cx2=Ia+Iw;
        *cx3=-Iw;
        *cx4=Ia+Ib+Iv+Iw;
        *cx5=-Ia-Iv-Iw;
        *cx6=0;
        *cx7=-Ia-Ib-Iu-Iv-Iw;
        *cx8=0;
        *cx9=0;
         break;
     case 67:

        *cx1=0;
        *cx2=Ia+Iw;
        *cx3=-Iw;
        *cx4=-Iu;
        *cx5=Ib+Iu;
        *cx6=0;
        *cx7=0;
        *cx8=-Ia-Ib-Iu-Iv-Iw;
        *cx9=0;
         break;
     case 68:

        *cx1=0;
        *cx2=-Ib-Iu-Iv;
        *cx3=Ia+Ib+Iu+Iv;
        *cx4=-Iu;
        *cx5=Ib+Iu;
        *cx6=0;
        *cx7=0;
        *cx8=0;
        *cx9=-Ia-Ib-Iu-Iv-Iw;
         break;
     case 69:

        *cx1=0;
        *cx2=-Iv;
        *cx3=Ia+Iv;
        *cx4=Ia+Ib+Iv+Iw;
        *cx5=0;
        *cx6=-Ia-Iv-Iw;
        *cx7=-Ia-Ib-Iu-Iv-Iw;
        *cx8=0;
        *cx9=0;
         break;
    case 70:

        *cx1=0;
        *cx2=Ia+Ib+Iu+Iw;
        *cx3=-Ib-Iu-Iw;
        *cx4=-Iu;
        *cx5=0;
        *cx6=Ib+Iu;
        *cx7=0;
        *cx8=-Ia-Ib-Iu-Iv-Iw;
        *cx9=0;
         break;
     case 71:

        *cx1=0;
        *cx2=-Iv;
        *cx3=Ia+Iv;
        *cx4=-Iu;
        *cx5=0;
        *cx6=Ib+Iu;
        *cx7=0;
        *cx8=0;
        *cx9=-Ia-Ib-Iu-Iv-Iw;
         break;
    case 72:

        *cx1=Ia+Iv+Iw;
        *cx2=-Iv;
        *cx3=-Iw;
        *cx4=Ib;
        *cx5=0;
        *cx6=0;
        *cx7=-Ia-Ib-Iu-Iv-Iw;
        *cx8=0;
        *cx9=0;
         break;
    case 73:

        *cx1=-Ib-Iu;
        *cx2=Ia+Ib+Iu+Iw;
        *cx3=-Iw;
        *cx4=Ib;
        *cx5=0;
        *cx6=0;
        *cx7=0;
        *cx8=-Ia-Ib-Iu-Iv-Iw;
        *cx9=0;
         break;
    case 74:

        *cx1=-Ib-Iu;
        *cx2=-Iv;
        *cx3=Ia+Ib+Iu+Iv;
        *cx4=Ib;
        *cx5=0;
        *cx6=0;
        *cx7=0;
        *cx8=0;
        *cx9=-Ia-Ib-Iu-Iv-Iw;
         break;
    case 75:

        *cx1=Ia+Ib+Iv+Iw;
        *cx2=-Ib-Iv;
        *cx3=-Iw;
        *cx4=0;
        *cx5=Ib;
        *cx6=0;
        *cx7=-Ia-Ib-Iu-Iv-Iw;
        *cx8=0;
        *cx9=0;
         break;
    case 76:

        *cx1=-Iu;
        *cx2=Ia+Iu+Iw;
        *cx3=-Iw;
        *cx4=0;
        *cx5=Ib;
        *cx6=0;
        *cx7=0;
        *cx8=-Ia-Ib-Iu-Iv-Iw;
        *cx9=0;
         break;
    case 77:

        *cx1=-Iu;
        *cx2=-Ib-Iv;
        *cx3=Ia+Ib+Iu+Iv;
        *cx4=0;
        *cx5=Ib;
        *cx6=0;
        *cx7=0;
        *cx8=0;
        *cx9=-Ia-Ib-Iu-Iv-Iw;
         break;
    case 78:

        *cx1=Ia+Ib+Iv+Iw;
        *cx2=-Iv;
        *cx3=-Ib-Iw;
        *cx4=0;
        *cx5=0;
        *cx6=Ib;
        *cx7=-Ia-Ib-Iu-Iv-Iw;
        *cx8=0;
        *cx9=0;
        break;

    case 79:

       	       *cx1=-Iu;
               *cx2=Ia+Ib+Iu+Iw;
               *cx3=-Ib-Iw;
               *cx4=0;
               *cx5=0;
               *cx6=Ib;
               *cx7=0;
               *cx8=-Ia-Ib-Iu-Iv-Iw;
               *cx9=0;
            break;

    case 80:

             *cx1=-Iu;
             *cx2=-Iv;
             *cx3=Ia+Iu+Iv;
             *cx4=0;
             *cx5=0;
             *cx6=Ib;
             *cx7=0;
             *cx8=0;
          break;



    default:
        	   *cx1=0;
               *cx2=0;
               *cx3=0;
               *cx4=0;
               *cx5=0;
               *cx6=0;
               *cx7=0;
               *cx8=0;
               *cx9=0;
            break;

}
}