int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
int V_6 = 0 ;
unsigned long V_7 ;
F_2 ( V_8 , 1 , V_2 , 0 ) ;
#ifdef F_3
F_4 ( L_1 , V_2 -> V_9 ) ;
F_4 ( L_2 , V_4 -> V_10 . V_11 ) ;
for ( V_5 = 0 ; V_5 < V_4 -> V_10 . V_11 ; V_5 ++ )
F_4 ( L_3 , V_5 , V_4 -> V_10 . V_12 [ V_5 ] . V_7 ,
( unsigned long ) V_4 -> V_10 . V_12 [ V_5 ] . V_13 ) ;
#endif
if ( V_4 -> V_10 . V_11 == 0 ) {
#ifdef F_3
F_4 ( L_4 , V_2 -> V_9 ) ;
#endif
if ( ! F_5 ( V_7 , ( V_14 V_15 * ) V_2 -> V_9 ) ) {
V_6 = F_6 ( V_7 , & V_4 -> V_10 . V_16 , V_4 -> V_10 . V_17 ) ;
if ( V_6 ) {
V_2 -> V_9 = V_2 -> V_18 ;
V_2 -> V_18 += 4 ;
}
}
return V_6 ;
}
for ( V_5 = 0 ; V_5 < V_4 -> V_10 . V_11 ; V_5 ++ ) {
V_6 = F_6 ( V_4 -> V_10 . V_12 [ V_5 ] . V_7 , & ( V_4 -> V_10 . V_16 ) , V_4 -> V_10 . V_17 ) ;
if ( ! V_6 )
break;
}
if ( V_6 )
V_4 -> V_10 . V_16 &= ~ ( 0x3000 | V_19 ) ;
else
V_4 -> V_10 . V_16 &= ~ 0x3000 ;
V_4 -> V_10 . V_11 = 0 ;
return V_6 ;
}
static inline int F_7 ( unsigned long * V_20 , int V_21 )
{
unsigned long V_16 = * V_20 ;
int V_22 ;
V_22 = ( V_16 & ( ( long ) V_21 << V_23 ) ) != 0UL ;
if ( V_22 != 0 ) {
V_21 &= ( ( V_16 & V_24 ) >> V_23 ) ;
if ( ( V_21 & ( V_21 - 1 ) ) != 0 ) {
if ( V_21 & V_25 )
V_21 = V_25 ;
else if ( V_21 & V_26 )
V_21 = V_26 ;
else if ( V_21 & V_27 )
V_21 = V_27 ;
else if ( V_21 & V_28 )
V_21 = V_28 ;
else if ( V_21 & V_29 )
V_21 = V_29 ;
}
}
V_16 &= ~ ( V_19 ) ;
V_16 |= ( ( long ) V_21 << V_30 ) ;
if ( V_22 == 0 )
V_16 |= ( ( long ) V_21 << V_31 ) ;
if ( V_22 != 0 )
V_16 |= ( 1UL << 14 ) ;
* V_20 = V_16 ;
return ( V_22 ? 0 : 1 ) ;
}
static int F_6 ( V_14 V_7 , unsigned long * V_20 , unsigned long * V_32 )
{
int type = 0 ;
#define TYPE ( T_1 , T_2 , T_3 , T_4 , T_5 , T_6 , T_7 ) type = (au << 2) | (a << 0) | (bu << 5) | (b << 3) | (ru << 8) | (r << 6)
int V_33 ;
T_8 V_34 = NULL , V_35 = NULL , V_36 = NULL ;
V_37 ;
F_8 ( V_38 ) ; F_8 ( V_39 ) ; F_8 ( V_40 ) ;
F_9 ( V_41 ) ; F_9 ( V_42 ) ; F_9 ( V_43 ) ;
F_10 ( V_44 ) ; F_10 ( V_45 ) ; F_10 ( V_46 ) ;
int V_47 ;
long V_16 ;
#ifdef F_3
F_4 ( L_5 , V_7 ) ;
#endif
if ( ( V_7 & 0xc1f80000 ) == 0x81a00000 ) {
switch ( ( V_7 >> 5 ) & 0x1ff ) {
case V_48 : TYPE ( 3 , 3 , 1 , 3 , 1 , 0 , 0 ) ; break;
case V_49 :
case V_50 :
case V_51 :
case V_52 : TYPE ( 3 , 3 , 1 , 3 , 1 , 3 , 1 ) ; break;
case V_53 : TYPE ( 3 , 3 , 1 , 2 , 1 , 2 , 1 ) ; break;
case V_54 : TYPE ( 3 , 1 , 1 , 3 , 1 , 0 , 0 ) ; break;
case V_55 : TYPE ( 3 , 2 , 1 , 3 , 1 , 0 , 0 ) ; break;
case V_56 : TYPE ( 3 , 3 , 1 , 1 , 0 , 0 , 0 ) ; break;
case V_57 : TYPE ( 3 , 3 , 1 , 1 , 1 , 0 , 0 ) ; break;
case V_58 : TYPE ( 3 , 3 , 1 , 2 , 1 , 0 , 0 ) ; break;
case V_59 : TYPE ( 3 , 1 , 0 , 3 , 1 , 0 , 0 ) ; break;
case V_60 : TYPE ( 2 , 1 , 1 , 1 , 1 , 0 , 0 ) ; break;
case V_61 : TYPE ( 2 , 2 , 1 , 2 , 1 , 0 , 0 ) ; break;
case V_62 :
case V_63 :
case V_64 :
case V_65 : TYPE ( 2 , 2 , 1 , 2 , 1 , 2 , 1 ) ; break;
case V_66 :
case V_67 :
case V_68 :
case V_69 : TYPE ( 2 , 1 , 1 , 1 , 1 , 1 , 1 ) ; break;
case V_70 : TYPE ( 2 , 2 , 1 , 1 , 1 , 1 , 1 ) ; break;
case V_71 : TYPE ( 2 , 1 , 1 , 2 , 1 , 0 , 0 ) ; break;
case V_72 : TYPE ( 2 , 2 , 1 , 1 , 1 , 0 , 0 ) ; break;
case V_73 : TYPE ( 2 , 1 , 0 , 1 , 1 , 0 , 0 ) ; break;
case V_74 : TYPE ( 2 , 1 , 0 , 2 , 1 , 0 , 0 ) ; break;
case V_75 : TYPE ( 2 , 1 , 1 , 1 , 0 , 0 , 0 ) ; break;
case V_76 : TYPE ( 2 , 2 , 1 , 1 , 0 , 0 , 0 ) ; break;
case V_77 :
case V_78 :
case V_79 : TYPE ( 2 , 1 , 0 , 1 , 0 , 0 , 0 ) ; break;
}
} else if ( ( V_7 & 0xc1f80000 ) == 0x81a80000 ) {
switch ( ( V_7 >> 5 ) & 0x1ff ) {
case V_80 : TYPE ( 3 , 0 , 0 , 1 , 1 , 1 , 1 ) ; break;
case V_81 : TYPE ( 3 , 0 , 0 , 1 , 1 , 1 , 1 ) ; break;
case V_82 : TYPE ( 3 , 0 , 0 , 2 , 1 , 2 , 1 ) ; break;
case V_83 : TYPE ( 3 , 0 , 0 , 2 , 1 , 2 , 1 ) ; break;
case V_84 : TYPE ( 3 , 0 , 0 , 3 , 1 , 3 , 1 ) ; break;
case V_85 : TYPE ( 3 , 0 , 0 , 3 , 1 , 3 , 1 ) ; break;
}
}
if ( ! type ) {
#ifdef F_3
F_4 ( L_6 ) ;
#endif
return 0 ;
}
V_33 = ( * V_20 >> 14 ) & 0xf ;
* V_20 &= ~ 0x1c000 ;
V_33 = ( ( V_7 >> 14 ) & 0x1f ) ;
switch ( type & 0x3 ) {
case 3 :
if ( V_33 & 3 ) {
* V_20 |= ( 6 << 14 ) ;
return 0 ;
}
case 2 :
if ( V_33 & 1 ) {
* V_20 |= ( 6 << 14 ) ;
return 0 ;
}
}
V_34 = ( T_8 ) & V_32 [ V_33 ] ;
switch ( type & 0x7 ) {
case 7 : F_11 ( V_44 , V_34 ) ; break;
case 6 : F_12 ( V_41 , V_34 ) ; break;
case 5 : F_13 ( V_38 , V_34 ) ; break;
}
V_33 = ( V_7 & 0x1f ) ;
switch ( ( type >> 3 ) & 0x3 ) {
case 3 :
if ( V_33 & 3 ) {
* V_20 |= ( 6 << 14 ) ;
return 0 ;
}
case 2 :
if ( V_33 & 1 ) {
* V_20 |= ( 6 << 14 ) ;
return 0 ;
}
}
V_35 = ( T_8 ) & V_32 [ V_33 ] ;
switch ( ( type >> 3 ) & 0x7 ) {
case 7 : F_11 ( V_45 , V_35 ) ; break;
case 6 : F_12 ( V_42 , V_35 ) ; break;
case 5 : F_13 ( V_39 , V_35 ) ; break;
}
V_33 = ( ( V_7 >> 25 ) & 0x1f ) ;
switch ( ( type >> 6 ) & 0x3 ) {
case 0 :
if ( V_33 ) {
* V_20 |= ( 6 << 14 ) ;
return 0 ;
}
break;
case 3 :
if ( V_33 & 3 ) {
* V_20 |= ( 6 << 14 ) ;
return 0 ;
}
case 2 :
if ( V_33 & 1 ) {
* V_20 |= ( 6 << 14 ) ;
return 0 ;
}
case 1 :
V_36 = ( void * ) & V_32 [ V_33 ] ;
break;
}
#ifdef F_3
F_4 ( L_7 ) ;
#endif
switch ( ( V_7 >> 5 ) & 0x1ff ) {
case V_66 : F_14 ( V_40 , V_38 , V_39 ) ; break;
case V_62 : F_15 ( V_43 , V_41 , V_42 ) ; break;
case V_49 : F_16 ( V_46 , V_44 , V_45 ) ; break;
case V_67 : F_17 ( V_40 , V_38 , V_39 ) ; break;
case V_63 : F_18 ( V_43 , V_41 , V_42 ) ; break;
case V_50 : F_19 ( V_46 , V_44 , V_45 ) ; break;
case V_68 : F_20 ( V_40 , V_38 , V_39 ) ; break;
case V_70 : F_21 ( V_86 , V_87 , 2 , 1 , V_41 , V_38 ) ;
F_21 ( V_86 , V_87 , 2 , 1 , V_42 , V_39 ) ;
case V_64 : F_22 ( V_43 , V_41 , V_42 ) ; break;
case V_53 : F_21 ( V_88 , V_86 , 4 , 2 , V_44 , V_41 ) ;
F_21 ( V_88 , V_86 , 4 , 2 , V_45 , V_42 ) ;
case V_51 : F_23 ( V_46 , V_44 , V_45 ) ; break;
case V_69 : F_24 ( V_40 , V_38 , V_39 ) ; break;
case V_65 : F_25 ( V_43 , V_41 , V_42 ) ; break;
case V_52 : F_26 ( V_46 , V_44 , V_45 ) ; break;
case V_60 : F_27 ( V_40 , V_39 ) ; break;
case V_61 : F_28 ( V_43 , V_42 ) ; break;
case V_48 : F_29 ( V_46 , V_45 ) ; break;
case V_77 : V_36 -> V_89 = V_35 -> V_89 ; break;
case V_78 : V_36 -> V_89 = V_35 -> V_89 & 0x7fffffff ; break;
case V_79 : V_36 -> V_89 = V_35 -> V_89 ^ 0x80000000 ; break;
case V_73 : F_30 ( V_47 , V_39 , 32 , 1 ) ; break;
case V_74 : F_31 ( V_47 , V_42 , 32 , 1 ) ; break;
case V_59 : F_32 ( V_47 , V_45 , 32 , 1 ) ; break;
case V_75 : V_47 = V_35 -> V_89 ; F_33 ( V_40 , V_47 , 32 , int ) ; break;
case V_76 : V_47 = V_35 -> V_89 ; F_34 ( V_43 , V_47 , 32 , int ) ; break;
case V_56 : V_47 = V_35 -> V_89 ; F_35 ( V_46 , V_47 , 32 , int ) ; break;
case V_72 : F_21 ( V_86 , V_87 , 2 , 1 , V_43 , V_39 ) ; break;
case V_57 : F_21 ( V_88 , V_87 , 4 , 1 , V_46 , V_39 ) ; break;
case V_58 : F_21 ( V_88 , V_86 , 4 , 2 , V_46 , V_42 ) ; break;
case V_71 : F_21 ( V_87 , V_86 , 1 , 2 , V_40 , V_42 ) ; break;
case V_54 : F_21 ( V_87 , V_88 , 1 , 4 , V_40 , V_45 ) ; break;
case V_55 : F_21 ( V_86 , V_88 , 2 , 4 , V_43 , V_45 ) ; break;
case V_80 :
case V_81 :
F_36 ( V_47 , V_39 , V_38 , 3 ) ;
if ( V_47 == 3 &&
( ( ( V_7 >> 5 ) & 0x1ff ) == V_81 ||
F_37 ( V_38 ) ||
F_37 ( V_39 ) ) )
F_38 ( V_25 ) ;
break;
case V_82 :
case V_83 :
F_39 ( V_47 , V_42 , V_41 , 3 ) ;
if ( V_47 == 3 &&
( ( ( V_7 >> 5 ) & 0x1ff ) == V_83 ||
F_40 ( V_41 ) ||
F_40 ( V_42 ) ) )
F_38 ( V_25 ) ;
break;
case V_84 :
case V_85 :
F_41 ( V_47 , V_45 , V_44 , 3 ) ;
if ( V_47 == 3 &&
( ( ( V_7 >> 5 ) & 0x1ff ) == V_85 ||
F_42 ( V_44 ) ||
F_42 ( V_45 ) ) )
F_38 ( V_25 ) ;
}
if ( ! V_90 ) {
switch ( ( type >> 6 ) & 0x7 ) {
case 0 : V_16 = * V_20 ;
if ( V_47 == - 1 ) V_47 = 2 ;
V_16 &= ~ 0xc00 ; V_16 |= ( V_47 << 10 ) ; break;
* V_20 = V_16 ;
break;
case 1 : V_36 -> V_89 = V_47 ; break;
case 5 : F_43 ( V_36 , V_40 ) ; break;
case 6 : F_44 ( V_36 , V_43 ) ; break;
case 7 : F_45 ( V_36 , V_46 ) ; break;
}
}
if ( V_91 == 0 )
return 1 ;
return F_7 ( V_20 , V_91 ) ;
}
