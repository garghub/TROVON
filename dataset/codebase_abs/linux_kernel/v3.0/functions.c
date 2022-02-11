T_1
F_1 ( T_1 * V_1 )
{
#ifdef F_2
T_1 V_2 ;
F_3 () ;
V_2 = F_4 ( * V_1 ) ;
if ( V_3 >= V_4 )
F_5 ( L_1 , ( T_1 ) V_1 , V_2 ) ;
return V_2 ;
#else
F_3 () ;
return F_4 ( * V_1 ) ;
#endif
}
void
F_6 ( T_1 * V_1 , T_1 V_2 )
{
#ifdef F_2
if ( V_3 >= V_4 )
F_5 ( L_2 , ( T_1 ) V_1 , V_2 ) ;
#endif
* V_1 = F_7 ( V_2 ) ;
F_8 () ;
}
void
F_9 ( T_2 * V_5 )
{
volatile T_1 V_2 ;
V_2 = * ( T_1 * ) & V_5 -> V_6 -> V_7 ;
}
STATIC void
F_10 ( unsigned long V_8 )
{
struct V_9 * V_10 = ( void * ) V_8 ;
if ( V_11 != V_12 )
{
if ( V_3 >= V_13 )
F_11 ( L_3 , V_14 , V_11 ) ;
return;
}
F_12 ( & V_10 -> V_15 ) ;
F_13 ( & V_10 -> V_16 , V_17 + V_10 -> V_18 ) ;
}
int F_14 ( struct V_9 * V_19 , void (* F_15) ( void * ) , void * V_20 , int V_21 )
{
V_19 -> V_22 = F_15 ;
V_19 -> V_23 = V_20 ;
V_19 -> V_18 = ( V_24 ) * ( V_21 / 1000 ) / 1000 ;
F_16 ( & V_19 -> V_15 , ( void * ) F_15 ) ;
F_17 ( & V_19 -> V_16 ) ;
{
T_2 * V_5 = ( T_2 * ) V_20 ;
V_19 -> V_16 . V_25 = ( unsigned long ) & V_5 -> V_10 ;
}
V_19 -> V_16 . V_26 = F_10 ;
return 0 ;
}
void
F_18 ( int V_21 , char * V_27 )
{
int V_28 ;
if ( V_21 >= 1000 )
{
F_19 ( V_21 / 1000 ) ;
V_28 = ( V_21 / 1000 ) * 1000 ;
V_28 = V_21 - V_28 ;
if ( V_28 )
{
F_20 ( V_28 ) ;
}
} else
{
F_20 ( V_21 ) ;
}
}
void
F_21 ( void )
{
#ifndef F_22
V_29 ++ ;
#else
F_20 ( 1 ) ;
#endif
}
void
F_23 ( void * V_30 , int V_31 )
{
switch ( V_31 )
{
case V_32 :
F_24 ( (struct V_33 * ) V_30 , 0 ) ;
break;
case V_34 :
F_24 ( (struct V_33 * ) V_30 , 1 ) ;
break;
default:
F_24 ( V_30 , V_31 ) ;
break;
}
}
int
F_25 ( void * V_35 )
{
struct V_36 * V_37 = (struct V_36 * ) V_35 ;
return ( F_26 ( V_37 ) ) ;
}
void
F_27 ( void * V_35 )
{
struct V_36 * V_37 = (struct V_36 * ) V_35 ;
F_28 ( V_37 ) ;
return;
}
void
F_29 ( void * V_35 )
{
struct V_36 * V_37 = (struct V_36 * ) V_35 ;
F_30 ( V_37 ) ;
return;
}
void
F_31 ( void * V_35 )
{
struct V_36 * V_38 = (struct V_36 * ) V_35 ;
F_32 ( V_38 ) ;
return;
}
void
F_33 ( void * V_35 )
{
struct V_36 * V_38 = (struct V_36 * ) V_35 ;
F_34 ( V_38 ) ;
return;
}
int
F_35 ( void * V_35 )
{
struct V_36 * V_37 = (struct V_36 * ) V_35 ;
return ( F_36 ( V_37 ) ) ;
}
void F_37 ( void * V_39 , T_3 V_40 , void * V_35 )
{
struct V_36 * V_37 = V_35 ;
struct V_41 * V_42 = V_39 ;
V_42 -> V_38 = V_37 ;
F_38 ( V_42 , V_40 ) ;
V_42 -> V_43 = F_39 ( V_42 , V_37 ) ;
F_40 ( V_42 ) ;
}
void
F_41 ( void * V_44 )
{
T_1 V_45 = ( T_1 ) V_44 ;
F_6 ( ( T_1 * ) & V_46 -> V_47 -> V_48 , V_45 ) ;
}
void
F_42 ( T_2 * V_5 , int V_44 )
{
T_4 * V_49 ;
volatile T_1 V_25 ;
V_49 = V_5 -> V_50 [ 0 ] . V_51 ;
switch ( V_44 )
{
default:
case 0 :
V_25 = F_1 ( ( T_1 * ) & V_49 -> V_52 ) ;
break;
case 1 :
V_25 = F_1 ( ( T_1 * ) & V_49 -> V_53 ) ;
break;
case 2 :
V_25 = F_1 ( ( T_1 * ) & V_49 -> V_54 ) ;
break;
case 3 :
V_25 = F_1 ( ( T_1 * ) & V_49 -> V_55 ) ;
break;
case 4 :
V_25 = F_1 ( ( T_1 * ) & V_49 -> V_56 ) ;
break;
case 5 :
V_25 = F_1 ( ( T_1 * ) & V_49 -> V_57 ) ;
break;
case 6 :
V_25 = F_1 ( ( T_1 * ) & V_49 -> V_58 ) ;
break;
case 7 :
V_25 = F_1 ( ( T_1 * ) & V_49 -> V_59 ) ;
break;
case 8 :
V_25 = F_1 ( ( T_1 * ) & V_49 -> V_60 ) ;
break;
case 9 :
V_25 = F_1 ( ( T_1 * ) & V_49 -> V_61 ) ;
break;
case 10 :
V_25 = F_1 ( ( T_1 * ) & V_49 -> V_62 ) ;
break;
case 11 :
V_25 = F_1 ( ( T_1 * ) & V_49 -> V_63 ) ;
break;
case 12 :
V_25 = F_1 ( ( T_1 * ) & V_49 -> V_64 ) ;
break;
case 13 :
V_25 = F_1 ( ( T_1 * ) & V_49 -> V_65 ) ;
break;
case 14 :
V_25 = F_1 ( ( T_1 * ) & V_49 -> V_66 ) ;
break;
case 15 :
V_25 = F_1 ( ( T_1 * ) & V_49 -> V_67 ) ;
break;
case 16 :
V_25 = F_1 ( ( T_1 * ) & V_49 -> V_68 ) ;
break;
case 17 :
V_25 = F_1 ( ( T_1 * ) & V_49 -> V_69 ) ;
break;
case 18 :
V_25 = F_1 ( ( T_1 * ) & V_49 -> V_70 ) ;
break;
case 19 :
V_25 = F_1 ( ( T_1 * ) & V_49 -> V_71 ) ;
break;
}
}
