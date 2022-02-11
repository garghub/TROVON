static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
int V_5 = V_1 -> V_6 ;
if ( V_5 && ! ( V_5 == - V_7
|| V_5 == - V_8 || V_5 == - V_9 ) )
F_2 ( L_1 ,
V_10 , V_5 ) ;
if ( ! F_3 ( V_11 , & V_3 -> V_12 ) )
return;
F_4 ( V_11 , & V_3 -> V_12 ) ;
F_5 ( & V_3 -> V_13 ) ;
}
static void F_6 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
int V_5 = V_1 -> V_6 ;
switch ( V_5 ) {
case 0 :
break;
case - V_7 :
case - V_8 :
case - V_9 :
break;
default:
F_2 ( L_1 ,
V_10 , V_5 ) ;
goto V_14;
}
goto exit;
V_14:
if ( F_3 ( V_15 , & V_3 -> V_12 ) && V_3 -> V_16 ) {
F_7 ( V_1 , & V_3 -> V_17 ) ;
if ( ! F_8 ( V_1 , V_18 ) )
goto exit;
F_9 ( & V_1 -> V_3 -> V_3 ,
L_2 ,
V_10 ) ;
F_10 ( V_1 ) ;
}
exit:
F_4 ( V_19 , & V_3 -> V_12 ) ;
F_5 ( & V_3 -> V_20 ) ;
}
static int F_11 ( struct V_2 * V_3 )
{
unsigned int V_21 ;
unsigned int V_22 ;
unsigned char V_23 [ 1 ] ;
unsigned char V_24 [ 2 ] ;
V_21 = F_12 ( V_3 -> V_25 , 0x01 ) ;
V_22 = F_13 ( V_3 -> V_25 , 0x81 ) ;
V_23 [ 0 ] = V_26 ;
F_14 ( V_3 -> V_25 , V_21 , V_23 , 1 , NULL , V_3 -> V_27 -> V_28 ) ;
F_14 ( V_3 -> V_25 , V_22 , V_24 , 2 , NULL , V_29 * 10 ) ;
return ( int ) V_24 [ 1 ] ;
}
static void F_15 ( struct V_2 * V_3 , int V_30 )
{
unsigned int V_21 ;
unsigned int V_22 ;
unsigned char V_23 [ 1 ] ;
unsigned char V_24 [ 64 ] ;
int V_31 ;
V_21 = F_12 ( V_3 -> V_25 , 0x01 ) ;
V_22 = F_13 ( V_3 -> V_25 , 0x81 ) ;
V_23 [ 0 ] = V_32 ;
F_14 ( V_3 -> V_25 , V_21 , V_23 , 1 , NULL , V_3 -> V_27 -> V_28 ) ;
F_14 ( V_3 -> V_25 , V_22 , V_24 , 64 , & V_31 , V_29 * 10 ) ;
V_24 [ V_31 ] = '\0' ;
if ( V_30 & V_33 )
strncpy ( V_3 -> V_34 . V_35 , V_24 + 1 , 24 ) ;
else
strncpy ( V_3 -> V_34 . V_36 , V_24 + 25 , 24 ) ;
}
static int F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_1 ;
unsigned int V_21 ;
int V_37 ;
T_1 V_38 ;
V_1 = F_17 ( 0 , V_18 ) ;
if ( ! V_1 )
return - V_39 ;
V_21 = F_18 ( V_3 -> V_25 , 0x01 ) ;
V_37 = V_3 -> V_27 -> V_28 ;
V_38 = F_19 ( V_3 -> V_27 -> V_40 ) ;
V_3 -> V_41 [ 0 ] = V_42 ;
V_3 -> V_41 [ 1 ] = 0x00 ;
V_3 -> V_41 [ 2 ] = 0x00 ;
V_3 -> V_41 [ 3 ] = 0x00 ;
V_3 -> V_41 [ 4 ] = 0x00 ;
V_3 -> V_41 [ 5 ] = 0x00 ;
V_3 -> V_41 [ 6 ] = 0x00 ;
V_3 -> V_41 [ 7 ] = 0x00 ;
F_20 ( V_1 , V_3 -> V_25 , V_21 , V_3 -> V_41 ,
V_38 , F_1 , V_3 , V_37 ) ;
F_7 ( V_1 , & V_3 -> V_43 ) ;
return F_8 ( V_1 , V_18 ) ;
}
static void F_21 ( struct V_1 * V_1 , int V_30 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
T_2 V_44 ;
T_2 V_45 ;
unsigned int V_46 ;
unsigned char * V_47 ;
T_1 V_38 ;
void (* F_22) ( struct V_1 * );
int V_37 ;
if ( V_30 & V_48 ) {
V_44 = V_3 -> V_49 -> V_50 ;
V_46 = F_23 ( V_3 -> V_25 , V_44 ) ;
V_47 = V_3 -> V_51 ;
V_38 = F_19 ( V_3 -> V_49 -> V_40 ) ;
F_22 = F_6 ;
V_37 = V_3 -> V_49 -> V_28 ;
} else {
V_45 = V_3 -> V_27 -> V_50 ;
V_46 = F_18 ( V_3 -> V_25 , V_45 ) ;
V_47 = V_3 -> V_41 ;
V_38 = F_19 ( V_3 -> V_27 -> V_40 ) ;
F_22 = F_1 ;
V_37 = V_3 -> V_27 -> V_28 ;
}
F_20 ( V_1 , V_3 -> V_25 , V_46 , V_47 , V_38 , F_22 , V_3 , V_37 ) ;
}
static void F_24 ( struct V_2 * V_3 )
{
T_2 V_45 ;
T_2 V_44 ;
unsigned int V_21 ;
unsigned int V_22 ;
T_1 V_38 ;
F_25 ( V_19 , & V_3 -> V_12 ) ;
F_25 ( V_11 , & V_3 -> V_12 ) ;
V_45 = V_3 -> V_27 -> V_50 ;
V_44 = V_3 -> V_49 -> V_50 ;
V_21 = F_12 ( V_3 -> V_25 , V_45 ) ;
V_22 = F_13 ( V_3 -> V_25 , V_44 ) ;
V_38 = F_19 ( V_3 -> V_27 -> V_40 ) ;
F_14 ( V_3 -> V_25 , V_21 , V_3 -> V_41 ,
V_38 , NULL , V_3 -> V_27 -> V_28 ) ;
F_14 ( V_3 -> V_25 , V_22 , V_3 -> V_51 , V_38 , NULL , V_29 * 10 ) ;
F_4 ( V_11 , & V_3 -> V_12 ) ;
F_4 ( V_19 , & V_3 -> V_12 ) ;
}
static int F_26 ( struct V_2 * V_3 )
{
struct V_1 * V_1 ;
int V_52 ;
if ( ! V_3 -> V_16 )
return - V_53 ;
if ( F_3 ( V_19 , & V_3 -> V_12 ) )
if ( F_27 ( V_3 -> V_20 ,
! F_3 ( V_19 ,
& V_3 -> V_12 ) ) )
return - V_54 ;
if ( V_3 -> V_55 . V_56 == V_57 ) {
F_24 ( V_3 ) ;
return 0 ;
}
V_1 = F_17 ( 0 , V_18 ) ;
if ( ! V_1 )
return - V_39 ;
V_1 -> V_4 = V_3 ;
F_21 ( V_1 , V_48 ) ;
F_25 ( V_15 , & V_3 -> V_12 ) ;
F_25 ( V_19 , & V_3 -> V_12 ) ;
F_7 ( V_1 , & V_3 -> V_17 ) ;
V_52 = F_8 ( V_1 , V_18 ) ;
if ( ! V_52 )
goto exit;
F_4 ( V_15 , & V_3 -> V_12 ) ;
F_10 ( V_1 ) ;
exit:
F_28 ( V_1 ) ;
return V_52 ;
}
static int F_29 ( struct V_2 * V_3 , int V_58 )
{
struct V_1 * V_1 ;
int V_52 ;
if ( ! V_3 -> V_16 )
return - V_53 ;
if ( F_3 ( V_11 , & V_3 -> V_12 ) )
if ( F_27 ( V_3 -> V_13 ,
! F_3 ( V_11 ,
& V_3 -> V_12 ) ) )
return - V_54 ;
if ( V_3 -> V_55 . V_56 == V_57 ) {
V_3 -> V_41 [ 0 ] = V_58 ;
F_24 ( V_3 ) ;
return 0 ;
}
V_1 = F_17 ( 0 , V_18 ) ;
if ( ! V_1 )
return - V_39 ;
V_1 -> V_4 = V_3 ;
F_21 ( V_1 , V_59 ) ;
F_25 ( V_11 , & V_3 -> V_12 ) ;
F_7 ( V_1 , & V_3 -> V_43 ) ;
V_3 -> V_41 [ 0 ] = V_58 ;
V_52 = F_8 ( V_1 , V_18 ) ;
if ( ! V_52 )
goto exit;
F_4 ( V_11 , & V_3 -> V_12 ) ;
F_10 ( V_1 ) ;
exit:
F_28 ( V_1 ) ;
return V_52 ;
}
static int F_30 ( struct V_2 * V_3 , int V_60 )
{
if ( ! V_3 )
return - V_61 ;
if ( ! V_3 -> V_62 )
return - V_53 ;
if ( ! V_3 -> V_63 )
return - V_53 ;
if ( V_60 & V_64 ) {
if ( F_3 ( V_19 , & V_3 -> V_12 ) )
return - V_65 ;
}
if ( V_60 & V_66 ) {
if ( F_3 ( V_11 , & V_3 -> V_12 ) )
return - V_65 ;
}
return 0 ;
}
static int F_31 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_72 , unsigned int * V_73 )
{
struct V_2 * V_3 = V_68 -> V_74 ;
int V_75 ;
int V_76 [ 2 ] ;
int V_77 ;
V_77 = F_30 ( V_3 , V_64 ) ;
if ( V_77 )
return V_77 ;
F_32 ( & V_3 -> V_78 ) ;
V_75 = F_33 ( V_72 -> V_79 ) ;
switch ( V_3 -> V_55 . V_56 ) {
case V_80 :
if ( ! V_75 )
V_76 [ 0 ] = V_81 ;
else
V_76 [ 0 ] = V_82 ;
break;
case V_57 :
default:
V_76 [ 0 ] = V_83 ;
V_76 [ 1 ] = V_84 ;
V_3 -> V_41 [ 0 ] = V_85 ;
V_3 -> V_41 [ V_86 ] = V_75 ;
break;
}
for ( V_77 = 0 ; V_77 < V_72 -> V_77 ; V_77 ++ ) {
if ( F_26 ( V_3 ) )
break;
if ( V_3 -> V_55 . V_56 == V_80 ) {
V_73 [ V_77 ] = V_3 -> V_51 [ V_76 [ 0 ] ] ;
continue;
}
V_73 [ V_77 ] = V_3 -> V_51 [ V_76 [ 0 ] ] + 256 *
V_3 -> V_51 [ V_76 [ 1 ] ] ;
}
F_34 ( & V_3 -> V_78 ) ;
return V_77 ;
}
static int F_35 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_72 , unsigned int * V_73 )
{
struct V_2 * V_3 = V_68 -> V_74 ;
int V_75 ;
int V_58 ;
int V_76 ;
int V_77 ;
V_77 = F_30 ( V_3 , V_66 ) ;
if ( V_77 )
return V_77 ;
F_32 ( & V_3 -> V_78 ) ;
V_75 = F_33 ( V_72 -> V_79 ) ;
switch ( V_3 -> V_55 . V_56 ) {
case V_80 :
V_58 = V_87 ;
if ( ! V_75 )
V_76 = V_88 ;
else
V_76 = V_89 ;
break;
default:
V_58 = V_90 ;
V_76 = V_91 ;
V_3 -> V_41 [ V_86 ] = V_75 ;
break;
}
for ( V_77 = 0 ; V_77 < V_72 -> V_77 ; V_77 ++ ) {
V_3 -> V_41 [ V_76 ] = V_73 [ V_77 ] ;
if ( F_29 ( V_3 , V_58 ) )
break;
}
F_34 ( & V_3 -> V_78 ) ;
return V_77 ;
}
static int F_36 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_72 , unsigned int * V_73 )
{
struct V_2 * V_3 = V_68 -> V_74 ;
int V_75 ;
int V_76 ;
int V_77 ;
V_77 = F_30 ( V_3 , V_64 ) ;
if ( V_77 )
return V_77 ;
F_32 ( & V_3 -> V_78 ) ;
V_75 = F_33 ( V_72 -> V_79 ) ;
V_76 = V_91 - 1 ;
V_3 -> V_41 [ 0 ] = V_92 ;
for ( V_77 = 0 ; V_77 < V_72 -> V_77 ; V_77 ++ ) {
if ( F_26 ( V_3 ) )
break;
V_73 [ V_77 ] = V_3 -> V_51 [ V_76 + V_75 ] ;
}
F_34 ( & V_3 -> V_78 ) ;
return V_77 ;
}
static int F_37 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_72 , unsigned int * V_73 )
{
struct V_2 * V_3 = V_68 -> V_74 ;
unsigned char * V_93 ;
int V_76 ;
int V_52 ;
V_52 = F_30 ( V_3 , V_64 ) ;
if ( V_52 )
return V_52 ;
F_32 ( & V_3 -> V_78 ) ;
V_93 = V_3 -> V_51 ;
if ( V_3 -> V_55 . V_56 == V_57 ) {
V_76 = V_94 ;
V_3 -> V_41 [ 0 ] = V_95 ;
} else {
V_76 = V_96 ;
}
V_52 = F_26 ( V_3 ) ;
if ( ! V_52 ) {
if ( V_3 -> V_55 . V_56 == V_80 )
V_73 [ 1 ] = ( ( ( V_93 [ V_76 ] >> 4 ) & 0x03 ) |
( ( V_93 [ V_76 ] << 2 ) & 0x04 ) |
( ( V_93 [ V_76 ] >> 3 ) & 0x18 ) ) ;
else
V_73 [ 1 ] = V_93 [ V_76 ] ;
V_52 = 2 ;
}
F_34 ( & V_3 -> V_78 ) ;
return V_52 ;
}
static int F_38 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_72 , unsigned int * V_73 )
{
struct V_2 * V_3 = V_68 -> V_74 ;
int V_75 ;
unsigned char * V_93 ;
int V_76 ;
int V_97 ;
int V_77 ;
V_77 = F_30 ( V_3 , V_64 ) ;
if ( V_77 )
return V_77 ;
F_32 ( & V_3 -> V_78 ) ;
V_75 = F_33 ( V_72 -> V_79 ) ;
V_93 = V_3 -> V_51 ;
if ( V_3 -> V_55 . V_56 == V_57 ) {
V_76 = V_94 ;
V_3 -> V_41 [ 0 ] = V_95 ;
} else {
V_76 = V_96 ;
}
for ( V_77 = 0 ; V_77 < V_72 -> V_77 ; V_77 ++ ) {
if ( F_26 ( V_3 ) )
break;
if ( V_3 -> V_55 . V_56 == V_80 )
V_97 = ( ( ( V_93 [ V_76 ] >> 4 ) & 0x03 ) |
( ( V_93 [ V_76 ] << 2 ) & 0x04 ) |
( ( V_93 [ V_76 ] >> 3 ) & 0x18 ) ) ;
else
V_97 = V_93 [ V_76 ] ;
V_73 [ V_77 ] = ( V_97 >> V_75 ) & 1 ;
}
F_34 ( & V_3 -> V_78 ) ;
return V_77 ;
}
static int F_39 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_72 , unsigned int * V_73 )
{
struct V_2 * V_3 = V_68 -> V_74 ;
int V_75 ;
unsigned char * V_98 ;
int V_76 ;
int V_58 ;
int V_77 ;
V_77 = F_30 ( V_3 , V_66 ) ;
if ( V_77 )
return V_77 ;
F_32 ( & V_3 -> V_78 ) ;
V_75 = F_33 ( V_72 -> V_79 ) ;
V_98 = V_3 -> V_41 ;
for ( V_77 = 0 ; V_77 < V_72 -> V_77 ; V_77 ++ ) {
if ( V_3 -> V_55 . V_56 == V_80 ) {
V_76 = V_99 ;
V_58 = V_87 ;
if ( V_73 [ V_77 ] == 1 )
V_98 [ V_76 ] |= ( 1 << V_75 ) ;
else
V_98 [ V_76 ] ^= ( 1 << V_75 ) ;
} else {
V_76 = V_100 ;
if ( V_73 [ V_77 ] == 1 ) {
V_58 = V_101 ;
V_98 [ V_76 ] = 1 << V_75 ;
} else {
V_58 = V_102 ;
V_98 [ V_76 ] = 0xff - ( 1 << V_75 ) ;
}
}
if ( F_29 ( V_3 , V_58 ) )
break;
}
F_34 ( & V_3 -> V_78 ) ;
return V_77 ;
}
static int F_40 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_72 , unsigned int * V_73 )
{
struct V_2 * V_3 = V_68 -> V_74 ;
int V_75 ;
int V_76 ;
int V_77 ;
V_77 = F_30 ( V_3 , V_64 ) ;
if ( V_77 )
return V_77 ;
F_32 ( & V_3 -> V_78 ) ;
V_75 = F_33 ( V_72 -> V_79 ) ;
V_76 = V_100 ;
V_3 -> V_41 [ 0 ] = V_103 ;
for ( V_77 = 0 ; V_77 < V_72 -> V_77 ; V_77 ++ ) {
if ( F_26 ( V_3 ) )
break;
V_73 [ V_77 ] = ( V_3 -> V_51 [ V_76 ] >> V_75 ) & 1 ;
}
F_34 ( & V_3 -> V_78 ) ;
return V_77 ;
}
static int F_41 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_72 , unsigned int * V_73 )
{
struct V_2 * V_3 = V_68 -> V_74 ;
unsigned char * V_93 , * V_98 ;
int V_60 , V_76 , V_58 ;
int V_52 ;
V_60 = 0 ;
if ( V_73 [ 0 ] )
V_60 |= V_66 ;
if ( V_3 -> V_55 . V_56 == V_57 )
V_60 |= V_64 ;
V_52 = F_30 ( V_3 , V_60 ) ;
if ( V_52 )
return V_52 ;
F_32 ( & V_3 -> V_78 ) ;
V_93 = V_3 -> V_51 ;
V_98 = V_3 -> V_41 ;
if ( V_73 [ 0 ] ) {
if ( V_3 -> V_55 . V_56 == V_80 ) {
V_76 = V_99 ;
V_58 = V_87 ;
} else {
V_76 = V_100 ;
V_58 = V_104 ;
}
V_98 [ V_76 ] &= ~ V_73 [ 0 ] ;
V_98 [ V_76 ] |= ( V_73 [ 0 ] & V_73 [ 1 ] ) ;
V_52 = F_29 ( V_3 , V_58 ) ;
if ( V_52 )
goto V_105;
}
if ( V_3 -> V_55 . V_56 == V_57 ) {
V_76 = V_100 ;
V_98 [ 0 ] = V_103 ;
V_52 = F_26 ( V_3 ) ;
if ( ! V_52 ) {
V_73 [ 1 ] = V_93 [ V_76 ] ;
V_52 = 2 ;
}
} else {
V_73 [ 1 ] = V_98 [ V_76 ] ;
V_52 = 2 ;
}
V_105:
F_34 ( & V_3 -> V_78 ) ;
return V_52 ;
}
static int F_42 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_72 , unsigned int * V_73 )
{
struct V_2 * V_3 = V_68 -> V_74 ;
int V_75 ;
int V_76 [ 2 ] ;
int V_77 ;
V_77 = F_30 ( V_3 , V_64 ) ;
if ( V_77 )
return V_77 ;
F_32 ( & V_3 -> V_78 ) ;
V_75 = F_33 ( V_72 -> V_79 ) ;
switch ( V_3 -> V_55 . V_56 ) {
case V_80 :
if ( ! V_75 )
V_76 [ 0 ] = V_106 ;
else
V_76 [ 0 ] = V_107 ;
break;
case V_57 :
default:
V_76 [ 0 ] = V_108 ;
V_76 [ 1 ] = V_108 ;
V_3 -> V_41 [ 0 ] = V_109 ;
break;
}
for ( V_77 = 0 ; V_77 < V_72 -> V_77 ; V_77 ++ ) {
if ( F_26 ( V_3 ) )
break;
if ( V_3 -> V_55 . V_56 == V_80 )
V_73 [ V_77 ] = V_3 -> V_51 [ V_76 [ 0 ] ] ;
else
V_73 [ V_77 ] = V_3 -> V_51 [ V_76 [ 0 ] * ( V_75 + 1 ) + 1 ]
+ 256 * V_3 -> V_51 [ V_76 [ 1 ] * 2 + 2 ] ;
}
F_34 ( & V_3 -> V_78 ) ;
return V_77 ;
}
static int F_43 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_72 , unsigned int * V_73 )
{
struct V_2 * V_3 = V_68 -> V_74 ;
unsigned int V_110 ;
int V_75 ;
int V_58 ;
int V_76 ;
int V_77 ;
V_77 = F_30 ( V_3 , V_66 ) ;
if ( V_77 )
return V_77 ;
V_110 = V_73 [ 0 ] ;
if ( V_110 != V_111 && V_110 != V_112 )
return - V_113 ;
F_32 ( & V_3 -> V_78 ) ;
V_75 = F_33 ( V_72 -> V_79 ) ;
if ( V_3 -> V_55 . V_56 == V_80 ) {
if ( ! V_75 ) {
V_58 = V_114 ;
V_76 = V_106 ;
} else {
V_58 = V_115 ;
V_76 = V_107 ;
}
V_3 -> V_41 [ V_76 ] = 0x00 ;
} else {
V_58 = V_116 ;
}
for ( V_77 = 0 ; V_77 < V_72 -> V_77 ; V_77 ++ )
if ( F_29 ( V_3 , V_58 ) )
break;
F_34 ( & V_3 -> V_78 ) ;
return V_77 ;
}
static int F_44 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_72 , unsigned int * V_73 )
{
struct V_2 * V_3 = V_68 -> V_74 ;
unsigned long V_117 ;
unsigned long V_118 ;
int V_75 ;
int V_58 ;
int V_77 ;
V_77 = F_30 ( V_3 , V_66 ) ;
if ( V_77 )
return V_77 ;
F_32 ( & V_3 -> V_78 ) ;
V_75 = F_33 ( V_72 -> V_79 ) ;
if ( ! V_75 )
V_58 = V_119 ;
else
V_58 = V_120 ;
for ( V_77 = 0 ; V_77 < V_72 -> V_77 ; V_77 ++ ) {
V_117 = V_73 [ V_77 ] ;
if ( V_117 == 0 )
V_117 = 1 ;
if ( V_117 > 7450 )
V_117 = 7450 ;
V_118 = F_45 ( V_117 * 1000 / 115 ) ;
if ( ( ( V_118 + 1 ) * V_118 ) < V_117 * 1000 / 115 )
V_118 += 1 ;
V_3 -> V_41 [ 6 + V_75 ] = V_118 ;
if ( F_29 ( V_3 , V_58 ) )
break;
}
F_34 ( & V_3 -> V_78 ) ;
return V_77 ;
}
static int F_46 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_72 , unsigned int * V_73 )
{
struct V_2 * V_3 = V_68 -> V_74 ;
int V_76 [ 2 ] ;
int V_77 ;
V_77 = F_30 ( V_3 , V_64 ) ;
if ( V_77 )
return V_77 ;
F_32 ( & V_3 -> V_78 ) ;
V_76 [ 0 ] = V_121 ;
V_76 [ 1 ] = V_122 ;
V_3 -> V_41 [ 0 ] = V_123 ;
for ( V_77 = 0 ; V_77 < V_72 -> V_77 ; V_77 ++ ) {
if ( F_26 ( V_3 ) )
break;
V_73 [ V_77 ] = V_3 -> V_51 [ V_76 [ 0 ] ] + 4 * V_3 -> V_51 [ V_76 [ 1 ] ] ;
}
F_34 ( & V_3 -> V_78 ) ;
return V_77 ;
}
static int F_47 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_72 , unsigned int * V_73 )
{
struct V_2 * V_3 = V_68 -> V_74 ;
unsigned char * V_98 ;
int V_76 [ 2 ] ;
int V_58 ;
int V_77 ;
V_77 = F_30 ( V_3 , V_66 ) ;
if ( V_77 )
return V_77 ;
F_32 ( & V_3 -> V_78 ) ;
V_98 = V_3 -> V_41 ;
V_76 [ 0 ] = V_121 ;
V_76 [ 1 ] = V_122 ;
V_58 = V_124 ;
for ( V_77 = 0 ; V_77 < V_72 -> V_77 ; V_77 ++ ) {
V_98 [ V_76 [ 0 ] ] = ( unsigned char ) ( V_73 [ V_77 ] & 0x03 ) ;
V_98 [ V_76 [ 1 ] ] = ( unsigned char ) ( V_73 [ V_77 ] >> 2 ) & 0xff ;
if ( F_29 ( V_3 , V_58 ) )
break;
}
F_34 ( & V_3 -> V_78 ) ;
return V_77 ;
}
static int F_48 ( struct V_67 * V_68 ,
struct V_2 * V_3 )
{
int V_125 ;
struct V_69 * V_70 ;
int V_126 ;
F_32 ( & V_3 -> V_78 ) ;
V_68 -> V_127 = V_3 -> V_55 . V_128 ;
V_68 -> V_74 = V_3 ;
if ( V_3 -> V_55 . V_56 == V_80 )
V_125 = 5 ;
else
V_125 = 6 ;
V_126 = F_49 ( V_68 , V_125 ) ;
if ( V_126 ) {
F_34 ( & V_3 -> V_78 ) ;
return V_126 ;
}
V_70 = & V_68 -> V_129 [ V_130 ] ;
V_70 -> type = V_131 ;
V_70 -> V_132 = V_133 | V_134 ;
V_70 -> V_135 = V_3 -> V_55 . V_136 ;
V_70 -> V_137 = ( 1 << V_3 -> V_55 . V_138 ) - 1 ;
V_70 -> V_139 = V_3 -> V_55 . V_140 ;
V_70 -> V_141 = F_31 ;
V_70 = & V_68 -> V_129 [ V_142 ] ;
V_70 -> type = V_143 ;
V_70 -> V_132 = V_144 | V_134 ;
V_70 -> V_135 = V_3 -> V_55 . V_145 ;
V_70 -> V_137 = ( 1 << V_3 -> V_55 . V_146 ) - 1 ;
V_70 -> V_139 = V_3 -> V_55 . V_140 ;
V_70 -> V_147 = F_35 ;
if ( V_3 -> V_55 . V_56 == V_57 ) {
V_70 -> V_132 |= V_133 ;
V_70 -> V_141 = F_36 ;
}
V_70 = & V_68 -> V_129 [ V_148 ] ;
V_70 -> type = V_149 ;
V_70 -> V_132 = V_133 | V_134 ;
V_70 -> V_135 = V_3 -> V_55 . V_150 ;
V_70 -> V_137 = 1 ;
V_70 -> V_141 = F_38 ;
V_70 -> V_151 = F_37 ;
V_70 = & V_68 -> V_129 [ V_152 ] ;
V_70 -> type = V_153 ;
V_70 -> V_132 = V_144 | V_134 ;
V_70 -> V_135 = V_3 -> V_55 . V_154 ;
V_70 -> V_137 = 1 ;
V_70 -> V_147 = F_39 ;
V_70 -> V_151 = F_41 ;
if ( V_3 -> V_55 . V_56 == V_57 ) {
V_70 -> V_132 |= V_133 ;
V_70 -> V_141 = F_40 ;
}
V_70 = & V_68 -> V_129 [ V_155 ] ;
V_70 -> type = V_156 ;
V_70 -> V_132 = V_133 ;
V_70 -> V_135 = V_3 -> V_55 . V_157 ;
V_70 -> V_141 = F_42 ;
V_70 -> V_158 = F_43 ;
if ( V_3 -> V_55 . V_56 == V_80 ) {
V_70 -> V_132 |= V_144 ;
V_70 -> V_137 = ( 1 << V_3 -> V_55 . V_159 ) - 1 ;
V_70 -> V_147 = F_44 ;
}
if ( V_3 -> V_55 . V_56 == V_57 ) {
V_70 = & V_68 -> V_129 [ V_160 ] ;
V_70 -> type = V_161 ;
V_70 -> V_132 = V_133 | V_144 ;
V_70 -> V_135 = V_3 -> V_55 . V_162 ;
V_70 -> V_137 = ( 1 << V_3 -> V_55 . V_163 ) - 1 ;
V_70 -> V_141 = F_46 ;
V_70 -> V_147 = F_47 ;
}
V_3 -> V_63 = 1 ;
F_50 ( V_68 -> V_164 , L_3 ,
V_3 -> V_165 , V_3 -> V_55 . V_128 ) ;
F_34 ( & V_3 -> V_78 ) ;
return 0 ;
}
static int F_51 ( struct V_67 * V_68 ,
struct V_166 * V_167 )
{
int V_168 ;
int V_126 ;
F_52 ( & V_169 ) ;
for ( V_168 = 0 ; V_168 < V_170 ; V_168 ++ )
if ( V_171 [ V_168 ] . V_62 && ! V_171 [ V_168 ] . V_63 )
break;
if ( V_168 == V_170 )
V_126 = - V_53 ;
else
V_126 = F_48 ( V_68 , & V_171 [ V_168 ] ) ;
F_53 ( & V_169 ) ;
return V_126 ;
}
static int F_54 ( struct V_67 * V_68 ,
struct V_172 * V_16 )
{
int V_168 ;
int V_126 ;
F_52 ( & V_169 ) ;
for ( V_168 = 0 ; V_168 < V_170 ; V_168 ++ )
if ( V_171 [ V_168 ] . V_62 && V_171 [ V_168 ] . V_16 == V_16 )
break;
if ( V_168 == V_170 )
V_126 = - V_53 ;
else if ( V_171 [ V_168 ] . V_63 )
V_126 = - V_65 ;
else
V_126 = F_48 ( V_68 , & V_171 [ V_168 ] ) ;
F_53 ( & V_169 ) ;
return V_126 ;
}
static void F_55 ( struct V_67 * V_3 )
{
struct V_2 * V_173 = V_3 -> V_74 ;
if ( V_173 ) {
F_32 ( & V_173 -> V_78 ) ;
V_3 -> V_74 = NULL ;
V_173 -> V_63 = 0 ;
F_34 ( & V_173 -> V_78 ) ;
}
}
static int F_56 ( struct V_172 * V_16 ,
const struct V_174 * V_175 )
{
int V_168 ;
struct V_2 * V_3 ;
struct V_176 * V_177 ;
struct V_178 * V_179 ;
T_1 V_38 ;
F_52 ( & V_169 ) ;
for ( V_168 = 0 ; V_168 < V_170 ; V_168 ++ )
if ( ! V_171 [ V_168 ] . V_62 )
break;
if ( V_168 == V_170 ) {
F_53 ( & V_169 ) ;
return - V_180 ;
}
V_3 = & V_171 [ V_168 ] ;
memset ( V_3 , 0x00 , sizeof( struct V_2 ) ) ;
V_3 -> V_165 = V_168 ;
V_177 = V_16 -> V_181 ;
if ( V_177 -> V_182 . V_183 != 2 )
goto error;
for ( V_168 = 0 ; V_168 < V_177 -> V_182 . V_183 ; V_168 ++ ) {
V_179 = & V_177 -> V_184 [ V_168 ] . V_182 ;
if ( F_57 ( V_179 ) ) {
V_3 -> V_49 = V_179 ;
continue;
}
if ( F_58 ( V_179 ) ) {
V_3 -> V_27 = V_179 ;
continue;
}
if ( F_59 ( V_179 ) ) {
V_3 -> V_49 = V_179 ;
continue;
}
if ( F_60 ( V_179 ) ) {
V_3 -> V_27 = V_179 ;
continue;
}
}
if ( ! V_3 -> V_49 || ! V_3 -> V_27 )
goto error;
V_38 = F_19 ( V_3 -> V_49 -> V_40 ) ;
V_3 -> V_51 = F_61 ( V_38 , V_18 ) ;
if ( ! V_3 -> V_51 ) {
F_53 ( & V_169 ) ;
return - V_39 ;
}
V_38 = F_19 ( V_3 -> V_27 -> V_40 ) ;
V_3 -> V_41 = F_61 ( V_38 , V_18 ) ;
if ( ! V_3 -> V_41 ) {
F_62 ( V_3 -> V_51 ) ;
F_53 ( & V_169 ) ;
return - V_39 ;
}
V_3 -> V_25 = F_63 ( V_16 ) ;
V_3 -> V_16 = V_16 ;
F_64 ( & V_3 -> V_78 , 8 ) ;
F_65 ( & V_3 -> V_20 ) ;
F_65 ( & V_3 -> V_13 ) ;
F_66 ( & V_3 -> V_17 ) ;
F_66 ( & V_3 -> V_43 ) ;
F_67 ( V_16 , V_3 ) ;
switch ( V_175 -> V_185 ) {
case V_186 :
V_3 -> V_55 . V_128 = L_4 ;
V_3 -> V_55 . V_56 = V_80 ;
V_3 -> V_55 . V_140 = & V_187 ;
V_3 -> V_55 . V_136 = 2 ;
V_3 -> V_55 . V_138 = 8 ;
V_3 -> V_55 . V_145 = 2 ;
V_3 -> V_55 . V_146 = 8 ;
V_3 -> V_55 . V_150 = 5 ;
V_3 -> V_55 . V_188 = 1 ;
V_3 -> V_55 . V_154 = 8 ;
V_3 -> V_55 . V_189 = 1 ;
V_3 -> V_55 . V_157 = 2 ;
V_3 -> V_55 . V_159 = 16 ;
V_3 -> V_55 . V_162 = 0 ;
V_3 -> V_55 . V_163 = 0 ;
break;
case V_190 :
V_3 -> V_55 . V_128 = L_5 ;
V_3 -> V_55 . V_56 = V_57 ;
V_3 -> V_55 . V_140 = & V_191 ;
V_3 -> V_55 . V_136 = 8 ;
V_3 -> V_55 . V_138 = 10 ;
V_3 -> V_55 . V_145 = 8 ;
V_3 -> V_55 . V_146 = 8 ;
V_3 -> V_55 . V_150 = 8 ;
V_3 -> V_55 . V_188 = 1 ;
V_3 -> V_55 . V_154 = 8 ;
V_3 -> V_55 . V_189 = 1 ;
V_3 -> V_55 . V_157 = 2 ;
V_3 -> V_55 . V_159 = 0 ;
V_3 -> V_55 . V_162 = 1 ;
V_3 -> V_55 . V_163 = 10 ;
break;
}
if ( V_3 -> V_55 . V_56 == V_57 ) {
F_15 ( V_3 , V_33 ) ;
F_68 ( V_192 L_6 , V_3 -> V_34 . V_35 ) ;
if ( F_11 ( V_3 ) ) {
F_15 ( V_3 , V_193 ) ;
F_68 ( V_192 L_6 ,
V_3 -> V_34 . V_36 ) ;
} else {
F_2 ( L_7 ) ;
}
}
if ( V_3 -> V_55 . V_56 == V_80 )
F_16 ( V_3 ) ;
V_3 -> V_62 = 1 ;
F_68 ( V_192 L_8 ,
V_3 -> V_165 , V_3 -> V_55 . V_128 ) ;
F_53 ( & V_169 ) ;
F_69 ( V_16 , & V_194 ) ;
return 0 ;
error:
F_53 ( & V_169 ) ;
return - V_53 ;
}
static void F_70 ( struct V_172 * V_16 )
{
struct V_2 * V_3 = F_71 ( V_16 ) ;
if ( ! V_3 )
return;
F_72 ( V_16 ) ;
F_52 ( & V_169 ) ;
F_32 ( & V_3 -> V_78 ) ;
V_3 -> V_62 = 0 ;
F_67 ( V_3 -> V_16 , NULL ) ;
F_73 ( & V_3 -> V_17 ) ;
F_73 ( & V_3 -> V_43 ) ;
F_62 ( V_3 -> V_51 ) ;
F_62 ( V_3 -> V_41 ) ;
F_68 ( V_192 L_9 ,
V_3 -> V_165 , V_3 -> V_55 . V_128 ) ;
F_34 ( & V_3 -> V_78 ) ;
F_53 ( & V_169 ) ;
}
