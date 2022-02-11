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
F_3 ( L_12 , V_12 -> V_20 ) ;
F_3 ( L_13 , V_12 -> V_21 ) ;
F_3 ( L_14 , V_12 -> V_22 ) ;
F_3 ( L_15 , V_12 -> V_23 . V_24 . V_25 ) ;
if ( V_12 -> V_23 . V_24 . V_25 == 0 ) {
union V_26 V_27 ;
V_27 . V_28 = F_4 ( V_29 ) ;
V_16 . V_28 = 0 ;
V_16 . V_24 . V_30 = V_27 . V_24 . V_27 ;
V_16 . V_24 . V_31 = 128 ;
V_16 . V_24 . V_32 = F_5 ( V_12 -> V_33 ) ;
if ( F_6 ( ! V_12 -> V_23 . V_24 . V_34 ) ) {
union V_35 V_36 ;
V_36 . V_28 = F_4 ( V_37 ) ;
V_16 . V_24 . V_32 +=
( V_36 . V_24 . V_38 << 3 ) -
V_12 -> V_23 . V_24 . V_39 ;
V_16 . V_24 . V_32 += ( V_12 -> V_23 . V_24 . V_40 ^ 1 ) << 2 ;
} else {
union V_41 V_42 ;
V_42 . V_28 = F_4 ( V_43 ) ;
V_16 . V_24 . V_32 += V_42 . V_24 . V_44 ;
}
} else
V_16 = V_12 -> V_45 ;
V_14 = V_12 -> V_20 ;
while ( V_14 ) {
V_17 =
( ( V_16 . V_24 . V_32 >> 7 ) - V_16 . V_24 . V_46 ) << 7 ;
F_3 ( L_16 ,
( unsigned long long ) V_17 ) ;
F_3 ( L_17 , V_16 . V_24 . V_47 ) ;
F_3 ( L_18 , V_16 . V_24 . V_46 ) ;
F_3 ( L_19 , V_16 . V_24 . V_30 ) ;
F_3 ( L_20 ,
( unsigned long long ) V_16 . V_24 . V_32 ) ;
F_3 ( L_21 , V_16 . V_24 . V_31 ) ;
F_3 ( L_22 ) ;
V_18 = ( T_4 * ) F_7 ( V_16 . V_24 . V_32 ) ;
V_19 = V_18 + V_16 . V_24 . V_31 ;
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
F_7 ( V_16 . V_24 . V_32 - 8 ) ;
}
return 0 ;
}
int F_8 ( int V_48 , int V_49 , int V_50 )
{
union V_51 V_52 ;
union V_53 V_54 ;
V_52 . V_28 = 0 ;
V_52 . V_24 . V_55 = V_50 ;
V_52 . V_24 . V_56 = V_49 ;
F_9 ( F_10 ( V_48 ) , V_52 . V_28 ) ;
V_54 . V_28 = 0 ;
V_54 . V_24 . V_57 =
( 255ul << 24 ) / ( V_52 . V_24 . V_56 - V_52 . V_24 . V_55 ) ;
V_54 . V_24 . V_58 = 1 ;
V_54 . V_24 . V_59 = 255 ;
V_54 . V_24 . V_60 = 1 ;
F_9 ( F_11 ( V_48 ) , V_54 . V_28 ) ;
return 0 ;
}
int F_12 ( int V_49 , int V_50 )
{
union V_61 V_62 ;
union V_63 V_64 ;
union V_65 V_66 ;
int V_48 ;
int V_67 ;
int V_68 ;
V_62 . V_28 = 0 ;
V_62 . V_24 . V_69 = 0 ;
V_62 . V_24 . V_62 = 100 ;
for ( V_67 = 0 ; V_67 < 2 ; V_67 ++ ) {
for ( V_68 = F_13 ( V_67 ) ;
V_68 < F_14 ( V_67 ) ; V_68 ++ )
F_9 ( F_15 ( V_68 ) ,
V_62 . V_28 ) ;
}
for ( V_48 = 0 ; V_48 < 8 ; V_48 ++ )
F_8 ( V_48 , V_49 , V_50 ) ;
V_64 . V_28 = 0 ;
V_64 . V_24 . V_70 = 0 ;
F_9 ( V_71 , V_64 . V_28 ) ;
V_66 . V_28 = 0 ;
V_66 . V_24 . V_70 = 0xfffffffffull ;
V_66 . V_24 . V_72 = 10000 ;
V_66 . V_24 . V_73 = 10000 ;
F_9 ( V_74 , V_66 . V_28 ) ;
return 0 ;
}
int F_16 ( int V_67 , int V_75 )
{
union V_76 V_77 ;
union V_78 V_79 ;
union V_80 V_81 ;
union V_82 V_83 ;
int V_84 ;
V_77 . V_28 = F_4 ( F_17 ( V_67 ) ) ;
V_77 . V_24 . V_85 = V_75 ;
F_9 ( F_17 ( V_67 ) , V_77 . V_28 ) ;
if ( F_18 ( V_67 ) ==
V_3
|| F_18 ( V_67 ) ==
V_8
|| F_18 ( V_67 ) ==
V_4
|| F_18 ( V_67 ) ==
V_7 ) {
if ( V_75 > 4 ) {
F_3 ( L_26
L_27 ) ;
return - 1 ;
}
V_79 . V_28 = F_4 ( F_19 ( V_67 ) ) ;
V_79 . V_24 . V_85 = V_75 ;
F_9 ( F_19 ( V_67 ) , V_79 . V_28 ) ;
}
if ( ! F_20 ( V_86 ) && ! F_20 ( V_87 )
&& ! F_20 ( V_88 ) ) {
V_81 . V_28 = F_4 ( V_89 ) ;
if ( V_67 == 0 ) {
if ( V_75 == 1 )
V_81 . V_24 . V_90 = 4 ;
else if ( V_75 == 2 )
V_81 . V_24 . V_90 = 3 ;
else if ( V_75 <= 4 )
V_81 . V_24 . V_90 = 2 ;
else if ( V_75 <= 8 )
V_81 . V_24 . V_90 = 1 ;
else
V_81 . V_24 . V_90 = 0 ;
} else {
if ( V_75 == 1 )
V_81 . V_24 . V_91 = 4 ;
else if ( V_75 == 2 )
V_81 . V_24 . V_91 = 3 ;
else if ( V_75 <= 4 )
V_81 . V_24 . V_91 = 2 ;
else if ( V_75 <= 8 )
V_81 . V_24 . V_91 = 1 ;
else
V_81 . V_24 . V_91 = 0 ;
}
F_9 ( V_89 , V_81 . V_28 ) ;
}
V_83 . V_28 = F_4 ( F_21 ( 0 , V_67 ) ) ;
if ( F_20 ( V_86 ) || F_20 ( V_87 )
|| F_20 ( V_88 ) ) {
V_83 . V_24 . V_92 = 0x40 ;
} else {
if ( V_75 <= 1 )
V_83 . V_24 . V_92 = 0x100 / 1 ;
else if ( V_75 == 2 )
V_83 . V_24 . V_92 = 0x100 / 2 ;
else
V_83 . V_24 . V_92 = 0x100 / 4 ;
}
if ( V_75 > 4 )
V_75 = 4 ;
for ( V_84 = 0 ; V_84 < V_75 ; V_84 ++ )
F_9 ( F_21 ( V_84 , V_67 ) ,
V_83 . V_28 ) ;
return 0 ;
}
int F_22 ( int V_67 , int V_68 )
{
switch ( V_67 ) {
case 0 :
return V_68 ;
case 1 :
return V_68 + 16 ;
case 2 :
return V_68 + 32 ;
case 3 :
return V_68 + 36 ;
}
return - 1 ;
}
int F_23 ( int V_93 )
{
if ( V_93 < 16 )
return 0 ;
else if ( V_93 < 32 )
return 1 ;
else if ( V_93 < 36 )
return 2 ;
else if ( V_93 < 40 )
return 3 ;
else
F_3 ( L_28
L_29 ) ;
return - 1 ;
}
int F_24 ( int V_93 )
{
if ( V_93 < 32 )
return V_93 & 15 ;
else if ( V_93 < 36 )
return V_93 & 3 ;
else if ( V_93 < 40 )
return V_93 & 3 ;
else
F_3 ( L_30
L_31 ) ;
return - 1 ;
}
