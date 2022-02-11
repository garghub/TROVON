int
F_1 ( void )
{
static int V_1 ;
if ( ! V_1 ) {
V_1 = 1 ;
F_2 ( V_2 , V_3 , V_4 , 0 ) ;
F_3 ( V_5 , 0 , 31 , V_6 ) ;
F_3 ( V_7 , 0 , 31 , V_6 ) ;
F_3 ( V_8 , 0 , 15 , V_6 ) ;
}
return 0 ;
}
int
F_3 ( int V_9 , int V_10 , int V_11 , enum V_12 V_13 )
{
int V_14 ;
unsigned long V_15 ;
F_1 () ;
if ( V_9 >= V_16 )
return - V_17 ;
F_4 ( & V_18 , V_15 ) ;
for ( V_14 = V_10 ; V_14 <= V_11 ; V_14 ++ ) {
if ( ( V_19 [ V_9 * V_20 + V_14 ] != V_21 ) &&
( V_19 [ V_9 * V_20 + V_14 ] != V_6 ) &&
( V_19 [ V_9 * V_20 + V_14 ] != V_13 ) ) {
F_5 ( & V_18 , V_15 ) ;
#ifdef F_6
F_7 ( L_1 ) ;
#endif
return - V_22 ;
}
}
for ( V_14 = V_10 ; V_14 <= V_11 ; V_14 ++ )
V_19 [ V_9 * V_20 + V_14 ] = V_13 ;
F_8 ( V_9 ) ;
F_5 ( & V_18 , V_15 ) ;
return 0 ;
}
int
F_9 ( enum V_23 V_24 )
{
int V_25 = - V_17 ;
char V_26 [ sizeof V_19 ] ;
unsigned long V_15 ;
F_4 ( & V_18 , V_15 ) ;
memcpy ( V_26 , V_19 , sizeof V_19 ) ;
F_1 () ;
T_1 V_27 = F_10 ( V_2 , V_3 , V_4 ) ;
T_2 V_28 = F_10 ( V_29 , V_30 ,
V_31 ) ;
switch ( V_24 ) {
case V_32 :
V_28 . V_33 = V_34 ;
V_28 . V_35 = V_34 ;
V_25 = F_3 ( V_7 , 8 , 23 , V_36 ) ;
V_25 |= F_3 ( V_7 , 24 , 25 , V_36 ) ;
V_27 . V_33 = V_27 . V_37 = V_38 ;
break;
case V_39 :
V_25 = F_3 ( V_7 , 0 , 7 , V_36 ) ;
V_27 . V_40 = V_38 ;
break;
case V_41 :
V_28 . V_42 = V_28 . V_43 = V_34 ;
V_25 = F_3 ( V_7 , 27 , 29 , V_36 ) ;
V_27 . V_44 = V_38 ;
break;
case V_45 :
V_28 . V_42 = V_28 . V_43 = V_34 ;
V_25 = F_3 ( V_7 , 27 , 31 , V_36 ) ;
V_25 |= F_3 ( V_8 , 0 , 15 , V_36 ) ;
V_27 . V_46 = V_27 . V_44 = V_38 ;
break;
case V_47 :
V_28 . V_48 = V_34 ;
V_25 = F_3 ( V_5 , 8 , 18 , V_36 ) ;
V_27 . V_49 = V_27 . V_50 = V_38 ;
break;
case V_51 :
V_28 . V_52 = V_34 ;
V_25 = F_3 ( V_5 , 24 , 25 , V_36 ) ;
V_27 . V_53 = V_38 ;
break;
case V_54 :
V_28 . V_52 = V_34 ;
V_25 = F_3 ( V_5 , 26 , 27 , V_36 ) ;
V_27 . V_55 = V_38 ;
break;
case V_56 :
V_28 . V_52 = V_34 ;
V_25 = F_3 ( V_5 , 28 , 29 , V_36 ) ;
V_27 . V_57 = V_38 ;
break;
case V_58 :
V_28 . V_52 = V_34 ;
V_25 = F_3 ( V_5 , 30 , 31 , V_36 ) ;
V_27 . V_59 = V_38 ;
break;
case V_60 :
V_28 . V_52 = V_34 ;
V_25 = F_3 ( V_5 , 19 , 23 , V_36 ) ;
V_27 . V_61 = V_38 ;
break;
case V_62 :
V_27 . V_63 = V_38 ;
V_25 = 0 ;
break;
case V_64 :
V_25 = F_3 ( V_5 , 30 , 30 , V_36 ) ;
V_27 . V_65 = V_38 ;
break;
case V_66 :
V_25 = F_3 ( V_5 , 31 , 31 , V_36 ) ;
V_27 . V_67 = V_38 ;
break;
case V_68 :
V_25 = F_3 ( V_7 , 26 , 26 , V_36 ) ;
V_27 . V_69 = V_38 ;
break;
case V_70 :
V_25 = F_3 ( V_5 , 0 , 1 , V_36 ) ;
V_27 . V_71 = V_38 ;
break;
case V_72 :
V_25 = F_3 ( V_5 , 2 , 3 , V_36 ) ;
V_27 . V_73 = V_38 ;
break;
case V_74 :
V_25 = F_3 ( V_5 , 2 , 3 , V_36 ) ;
V_25 |= F_3 ( V_5 , 7 , 7 , V_36 ) ;
V_27 . V_73 = V_27 . V_75 = V_38 ;
break;
case V_76 :
V_25 = F_3 ( V_5 , 2 , 4 , V_36 ) ;
V_27 . V_73 = V_27 . V_77 = V_38 ;
break;
case V_78 :
V_25 = F_3 ( V_5 , 2 , 3 , V_36 ) ;
V_25 |= F_3 ( V_5 , 5 , 5 , V_36 ) ;
V_27 . V_73 = V_27 . V_79 = V_38 ;
break;
case V_80 :
V_25 = F_3 ( V_5 , 2 , 3 , V_36 ) ;
V_25 |= F_3 ( V_5 , 6 , 6 , V_36 ) ;
V_27 . V_73 = V_27 . V_81 = V_38 ;
break;
default:
V_25 = - V_17 ;
break;
}
if ( ! V_25 ) {
F_11 ( V_2 , V_3 , V_4 , V_27 ) ;
F_11 ( V_29 , V_30 , V_31 , V_28 ) ;
} else
memcpy ( V_19 , V_26 , sizeof V_19 ) ;
F_5 ( & V_18 , V_15 ) ;
return V_25 ;
}
void
F_8 ( int V_9 )
{
int V_14 ;
int V_82 = 0 ;
int V_83 = 0 ;
int V_84 = V_9 * V_20 ;
for ( V_14 = 0 ; ( V_14 < V_20 ) && ( V_84 < V_85 ) ; V_14 ++ , V_84 ++ ) {
if ( V_19 [ V_84 ] == V_6 )
V_82 |= ( 1 << V_14 ) ;
else if ( V_19 [ V_84 ] == V_86 )
V_83 |= ( 1 << V_14 ) ;
}
F_12 ( int , V_3 + V_87 + 4 * V_9 ,
V_82 ) ;
F_12 ( int , V_3 + V_88 + 4 * V_9 ,
V_83 ) ;
#ifdef F_6
F_13 () ;
#endif
}
int
F_14 ( int V_9 , int V_10 , int V_11 )
{
int V_14 ;
unsigned long V_15 ;
F_1 () ;
if ( V_9 > V_16 || V_9 < 0 )
return - V_17 ;
F_4 ( & V_18 , V_15 ) ;
for ( V_14 = V_10 ; V_14 <= V_11 ; V_14 ++ )
V_19 [ V_9 * V_20 + V_14 ] = V_21 ;
F_8 ( V_9 ) ;
F_5 ( & V_18 , V_15 ) ;
return 0 ;
}
int
F_15 ( enum V_23 V_24 )
{
int V_25 = - V_17 ;
char V_26 [ sizeof V_19 ] ;
unsigned long V_15 ;
F_4 ( & V_18 , V_15 ) ;
memcpy ( V_26 , V_19 , sizeof V_19 ) ;
F_1 () ;
T_1 V_27 = F_10 ( V_2 , V_3 , V_4 ) ;
switch ( V_24 ) {
case V_32 :
V_25 = F_14 ( V_7 , 8 , 23 ) ;
V_25 |= F_14 ( V_7 , 24 , 25 ) ;
V_25 |= F_14 ( V_7 , 0 , 7 ) ;
V_27 . V_33 = V_27 . V_37 = V_27 . V_40 = V_89 ;
break;
case V_41 :
V_25 = F_14 ( V_7 , 27 , 29 ) ;
V_27 . V_44 = V_89 ;
break;
case V_45 :
V_25 = F_14 ( V_7 , 27 , 31 ) ;
V_25 |= F_14 ( V_8 , 0 , 15 ) ;
V_27 . V_46 = V_27 . V_44 = V_89 ;
break;
case V_47 :
V_25 = F_14 ( V_5 , 8 , 18 ) ;
V_27 . V_49 = V_27 . V_50 = V_89 ;
break;
case V_51 :
V_25 = F_14 ( V_5 , 24 , 25 ) ;
V_27 . V_53 = V_89 ;
break;
case V_54 :
V_25 = F_14 ( V_5 , 26 , 27 ) ;
V_27 . V_55 = V_89 ;
break;
case V_56 :
V_25 = F_14 ( V_5 , 28 , 29 ) ;
V_27 . V_57 = V_89 ;
break;
case V_58 :
V_25 = F_14 ( V_5 , 30 , 31 ) ;
V_27 . V_59 = V_89 ;
break;
case V_60 :
V_25 = F_14 ( V_5 , 19 , 23 ) ;
V_27 . V_61 = V_89 ;
break;
case V_64 :
V_25 = F_14 ( V_5 , 30 , 30 ) ;
V_27 . V_65 = V_89 ;
break;
case V_66 :
V_25 = F_14 ( V_5 , 31 , 31 ) ;
V_27 . V_67 = V_89 ;
break;
case V_68 :
V_25 = F_14 ( V_7 , 26 , 26 ) ;
V_27 . V_69 = V_89 ;
break;
case V_70 :
V_25 = F_14 ( V_5 , 0 , 1 ) ;
V_27 . V_71 = V_89 ;
break;
case V_72 :
V_25 = F_14 ( V_5 , 2 , 3 ) ;
V_27 . V_73 = V_89 ;
break;
case V_74 :
V_25 = F_14 ( V_5 , 2 , 3 ) ;
V_25 |= F_14 ( V_5 , 7 , 7 ) ;
V_27 . V_73 = V_27 . V_75 = V_89 ;
break;
case V_76 :
V_25 = F_14 ( V_5 , 2 , 4 ) ;
V_27 . V_77 = V_89 ;
break;
case V_78 :
V_25 = F_14 ( V_5 , 2 , 3 ) ;
V_25 |= F_14 ( V_5 , 5 , 5 ) ;
V_27 . V_79 = V_89 ;
break;
case V_80 :
V_25 = F_14 ( V_5 , 2 , 3 ) ;
V_25 |= F_14 ( V_5 , 6 , 6 ) ;
V_27 . V_81 = V_89 ;
break;
default:
V_25 = - V_17 ;
break;
}
if ( ! V_25 )
F_11 ( V_2 , V_3 , V_4 , V_27 ) ;
else
memcpy ( V_19 , V_26 , sizeof V_19 ) ;
F_5 ( & V_18 , V_15 ) ;
return V_25 ;
}
void
F_13 ( void )
{
int V_14 , V_90 ;
int V_84 = 0 ;
F_1 () ;
for ( V_14 = 0 ; V_14 < V_16 ; V_14 ++ ) {
V_84 ++ ;
F_16 ( V_91 L_2 , 'A' + V_14 ) ;
for ( V_90 = 0 ; ( V_90 < V_20 ) && ( V_84 < V_85 ) ; V_90 ++ , V_84 ++ )
F_16 ( V_91
L_3 , V_90 , V_19 [ V_14 * V_20 + V_90 ] ) ;
}
}
