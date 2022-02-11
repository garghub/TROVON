const char * F_1 ( T_1
V_1 )
{
switch ( V_1 ) {
case V_2 :
return L_1 ;
case V_3 :
return L_2 ;
case V_4 :
return L_3 ;
case V_5 :
return L_4 ;
case V_6 :
return L_5 ;
case V_7 :
return L_6 ;
case V_8 :
return L_7 ;
case V_9 :
return L_8 ;
case V_10 :
return L_9 ;
case V_11 :
return L_10 ;
}
return L_11 ;
}
int F_2 ( T_2 * V_12 )
{
T_3 V_13 ;
T_3 V_14 ;
union V_15 V_16 ;
T_3 V_17 ;
T_4 * V_18 ;
T_4 * V_19 ;
F_3 ( L_12 , V_12 -> V_20 . V_21 ) ;
F_3 ( L_13 , F_4 ( V_12 ) ) ;
F_3 ( L_14 , F_5 ( V_12 ) ) ;
F_3 ( L_15 , V_12 -> V_22 . V_23 . V_24 ) ;
if ( V_12 -> V_22 . V_23 . V_24 == 0 ) {
union V_25 V_26 ;
V_26 . V_27 = F_6 ( V_28 ) ;
V_16 . V_27 = 0 ;
V_16 . V_23 . V_29 = V_26 . V_23 . V_26 ;
V_16 . V_23 . V_30 = 128 ;
V_16 . V_23 . V_31 = F_7 ( V_12 -> V_32 ) ;
if ( F_8 ( ! V_12 -> V_22 . V_23 . V_33 ) ) {
union V_34 V_35 ;
V_35 . V_27 = F_6 ( V_36 ) ;
V_16 . V_23 . V_31 +=
( V_35 . V_23 . V_37 << 3 ) -
V_12 -> V_22 . V_23 . V_38 ;
V_16 . V_23 . V_31 += ( V_12 -> V_22 . V_23 . V_39 ^ 1 ) << 2 ;
} else {
union V_40 V_41 ;
V_41 . V_27 = F_6 ( V_42 ) ;
V_16 . V_23 . V_31 += V_41 . V_23 . V_43 ;
}
} else
V_16 = V_12 -> V_44 ;
V_14 = V_12 -> V_20 . V_21 ;
while ( V_14 ) {
V_17 =
( ( V_16 . V_23 . V_31 >> 7 ) - V_16 . V_23 . V_45 ) << 7 ;
F_3 ( L_16 ,
( unsigned long long ) V_17 ) ;
F_3 ( L_17 , V_16 . V_23 . V_46 ) ;
F_3 ( L_18 , V_16 . V_23 . V_45 ) ;
F_3 ( L_19 , V_16 . V_23 . V_29 ) ;
F_3 ( L_20 ,
( unsigned long long ) V_16 . V_23 . V_31 ) ;
F_3 ( L_21 , V_16 . V_23 . V_30 ) ;
F_3 ( L_22 ) ;
V_18 = ( T_4 * ) F_9 ( V_16 . V_23 . V_31 ) ;
V_19 = V_18 + V_16 . V_23 . V_30 ;
V_13 = 0 ;
while ( V_18 < V_19 ) {
if ( V_14 == 0 )
break;
else
V_14 -- ;
F_3 ( L_23 , ( unsigned int ) * V_18 ) ;
V_18 ++ ;
if ( V_14 && ( V_13 == 7 ) ) {
F_3 ( L_24 ) ;
V_13 = 0 ;
} else
V_13 ++ ;
}
F_3 ( L_25 ) ;
if ( V_14 )
V_16 = * (union V_15 * )
F_9 ( V_16 . V_23 . V_31 - 8 ) ;
}
return 0 ;
}
int F_10 ( int V_47 , int V_48 , int V_49 )
{
union V_50 V_51 ;
union V_52 V_53 ;
V_51 . V_27 = 0 ;
V_51 . V_23 . V_54 = V_49 ;
V_51 . V_23 . V_55 = V_48 ;
F_11 ( F_12 ( V_47 ) , V_51 . V_27 ) ;
V_53 . V_27 = 0 ;
V_53 . V_23 . V_56 =
( 255ul << 24 ) / ( V_51 . V_23 . V_55 - V_51 . V_23 . V_54 ) ;
V_53 . V_23 . V_57 = 1 ;
V_53 . V_23 . V_58 = 255 ;
V_53 . V_23 . V_59 = 1 ;
F_11 ( F_13 ( V_47 ) , V_53 . V_27 ) ;
return 0 ;
}
int F_14 ( int V_48 , int V_49 )
{
union V_60 V_61 ;
union V_62 V_63 ;
union V_64 V_65 ;
int V_47 ;
int V_66 ;
int V_67 ;
V_61 . V_27 = 0 ;
V_61 . V_23 . V_68 = 0 ;
V_61 . V_23 . V_61 = 100 ;
for ( V_66 = 0 ; V_66 < 2 ; V_66 ++ ) {
for ( V_67 = F_15 ( V_66 ) ;
V_67 < F_16 ( V_66 ) ; V_67 ++ )
F_11 ( F_17 ( V_67 ) ,
V_61 . V_27 ) ;
}
for ( V_47 = 0 ; V_47 < 8 ; V_47 ++ )
F_10 ( V_47 , V_48 , V_49 ) ;
V_63 . V_27 = 0 ;
V_63 . V_23 . V_69 = 0 ;
F_11 ( V_70 , V_63 . V_27 ) ;
V_65 . V_27 = 0 ;
V_65 . V_23 . V_69 = 0xfffffffffull ;
V_65 . V_23 . V_71 = 10000 ;
V_65 . V_23 . V_72 = 10000 ;
F_11 ( V_73 , V_65 . V_27 ) ;
return 0 ;
}
int F_18 ( int V_66 , int V_74 )
{
union V_75 V_76 ;
union V_77 V_78 ;
union V_79 V_80 ;
union V_81 V_82 ;
int V_83 ;
V_76 . V_27 = F_6 ( F_19 ( V_66 ) ) ;
V_76 . V_23 . V_84 = V_74 ;
F_11 ( F_19 ( V_66 ) , V_76 . V_27 ) ;
if ( F_20 ( V_66 ) ==
V_3
|| F_20 ( V_66 ) ==
V_8
|| F_20 ( V_66 ) ==
V_4
|| F_20 ( V_66 ) ==
V_7 ) {
if ( V_74 > 4 ) {
F_3 ( L_26
L_27 ) ;
return - 1 ;
}
V_78 . V_27 = F_6 ( F_21 ( V_66 ) ) ;
V_78 . V_23 . V_84 = V_74 ;
F_11 ( F_21 ( V_66 ) , V_78 . V_27 ) ;
}
if ( ! F_22 ( V_85 ) && ! F_22 ( V_86 )
&& ! F_22 ( V_87 ) ) {
V_80 . V_27 = F_6 ( V_88 ) ;
if ( V_66 == 0 ) {
if ( V_74 == 1 )
V_80 . V_23 . V_89 = 4 ;
else if ( V_74 == 2 )
V_80 . V_23 . V_89 = 3 ;
else if ( V_74 <= 4 )
V_80 . V_23 . V_89 = 2 ;
else if ( V_74 <= 8 )
V_80 . V_23 . V_89 = 1 ;
else
V_80 . V_23 . V_89 = 0 ;
} else {
if ( V_74 == 1 )
V_80 . V_23 . V_90 = 4 ;
else if ( V_74 == 2 )
V_80 . V_23 . V_90 = 3 ;
else if ( V_74 <= 4 )
V_80 . V_23 . V_90 = 2 ;
else if ( V_74 <= 8 )
V_80 . V_23 . V_90 = 1 ;
else
V_80 . V_23 . V_90 = 0 ;
}
F_11 ( V_88 , V_80 . V_27 ) ;
}
V_82 . V_27 = F_6 ( F_23 ( 0 , V_66 ) ) ;
if ( F_22 ( V_85 ) || F_22 ( V_86 )
|| F_22 ( V_87 ) ) {
V_82 . V_23 . V_91 = 0x40 ;
} else {
if ( V_74 <= 1 )
V_82 . V_23 . V_91 = 0x100 / 1 ;
else if ( V_74 == 2 )
V_82 . V_23 . V_91 = 0x100 / 2 ;
else
V_82 . V_23 . V_91 = 0x100 / 4 ;
}
if ( V_74 > 4 )
V_74 = 4 ;
for ( V_83 = 0 ; V_83 < V_74 ; V_83 ++ )
F_11 ( F_23 ( V_83 , V_66 ) ,
V_82 . V_27 ) ;
return 0 ;
}
int F_24 ( int V_66 , int V_67 )
{
switch ( V_66 ) {
case 0 :
return V_67 ;
case 1 :
return V_67 + 16 ;
case 2 :
return V_67 + 32 ;
case 3 :
return V_67 + 36 ;
case 4 :
return V_67 + 40 ;
case 5 :
return V_67 + 44 ;
}
return - 1 ;
}
int F_25 ( int V_92 )
{
if ( V_92 < 16 )
return 0 ;
else if ( V_92 < 32 )
return 1 ;
else if ( V_92 < 36 )
return 2 ;
else if ( V_92 < 40 )
return 3 ;
else if ( V_92 < 44 )
return 4 ;
else if ( V_92 < 48 )
return 5 ;
else
F_3 ( L_28
L_29 ) ;
return - 1 ;
}
int F_26 ( int V_92 )
{
if ( V_92 < 32 )
return V_92 & 15 ;
else if ( V_92 < 36 )
return V_92 & 3 ;
else if ( V_92 < 40 )
return V_92 & 3 ;
else if ( V_92 < 44 )
return V_92 & 3 ;
else if ( V_92 < 48 )
return V_92 & 3 ;
else
F_3 ( L_30
L_31 ) ;
return - 1 ;
}
