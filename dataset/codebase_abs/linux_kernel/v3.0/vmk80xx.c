static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
int V_5 = V_1 -> V_6 ;
F_2 ( L_1 , V_7 ) ;
if ( V_5 && ! ( V_5 == - V_8
|| V_5 == - V_9 || V_5 == - V_10 ) )
F_3 ( L_2 ,
V_7 , V_5 ) ;
if ( ! F_4 ( V_11 , & V_3 -> V_12 ) )
return;
F_5 ( V_11 , & V_3 -> V_12 ) ;
F_6 ( & V_3 -> V_13 ) ;
}
static void F_7 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
int V_5 = V_1 -> V_6 ;
F_2 ( L_1 , V_7 ) ;
switch ( V_5 ) {
case 0 :
break;
case - V_8 :
case - V_9 :
case - V_10 :
break;
default:
F_3 ( L_2 ,
V_7 , V_5 ) ;
goto V_14;
}
goto exit;
V_14:
if ( F_4 ( V_15 , & V_3 -> V_12 ) && V_3 -> V_16 ) {
F_8 ( V_1 , & V_3 -> V_17 ) ;
if ( ! F_9 ( V_1 , V_18 ) )
goto exit;
F_10 ( L_3 , V_7 ) ;
F_11 ( V_1 ) ;
}
exit:
F_5 ( V_19 , & V_3 -> V_12 ) ;
F_6 ( & V_3 -> V_20 ) ;
}
static int F_12 ( struct V_2 * V_3 )
{
unsigned int V_21 ;
unsigned int V_22 ;
unsigned char V_23 [ 1 ] ;
unsigned char V_24 [ 2 ] ;
F_2 ( L_1 , V_7 ) ;
V_21 = F_13 ( V_3 -> V_25 , 0x01 ) ;
V_22 = F_14 ( V_3 -> V_25 , 0x81 ) ;
V_23 [ 0 ] = V_26 ;
F_15 ( V_3 -> V_25 , V_21 , V_23 , 1 , NULL , V_3 -> V_27 -> V_28 ) ;
F_15 ( V_3 -> V_25 , V_22 , V_24 , 2 , NULL , V_29 * 10 ) ;
return ( int ) V_24 [ 1 ] ;
}
static void F_16 ( struct V_2 * V_3 , int V_30 )
{
unsigned int V_21 ;
unsigned int V_22 ;
unsigned char V_23 [ 1 ] ;
unsigned char V_24 [ 64 ] ;
int V_31 ;
F_2 ( L_1 , V_7 ) ;
V_21 = F_13 ( V_3 -> V_25 , 0x01 ) ;
V_22 = F_14 ( V_3 -> V_25 , 0x81 ) ;
V_23 [ 0 ] = V_32 ;
F_15 ( V_3 -> V_25 , V_21 , V_23 , 1 , NULL , V_3 -> V_27 -> V_28 ) ;
F_15 ( V_3 -> V_25 , V_22 , V_24 , 64 , & V_31 , V_29 * 10 ) ;
V_24 [ V_31 ] = '\0' ;
if ( V_30 & V_33 )
strncpy ( V_3 -> V_34 . V_35 , V_24 + 1 , 24 ) ;
else
strncpy ( V_3 -> V_34 . V_36 , V_24 + 25 , 24 ) ;
}
static int F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_1 ;
unsigned int V_21 ;
int V_37 ;
T_1 V_38 ;
F_2 ( L_1 , V_7 ) ;
V_1 = F_18 ( 0 , V_18 ) ;
if ( ! V_1 )
return - V_39 ;
V_21 = F_19 ( V_3 -> V_25 , 0x01 ) ;
V_37 = V_3 -> V_27 -> V_28 ;
V_38 = F_20 ( V_3 -> V_27 -> V_40 ) ;
V_3 -> V_41 [ 0 ] = V_42 ;
V_3 -> V_41 [ 1 ] = 0x00 ;
V_3 -> V_41 [ 2 ] = 0x00 ;
V_3 -> V_41 [ 3 ] = 0x00 ;
V_3 -> V_41 [ 4 ] = 0x00 ;
V_3 -> V_41 [ 5 ] = 0x00 ;
V_3 -> V_41 [ 6 ] = 0x00 ;
V_3 -> V_41 [ 7 ] = 0x00 ;
F_21 ( V_1 , V_3 -> V_25 , V_21 , V_3 -> V_41 ,
V_38 , F_1 , V_3 , V_37 ) ;
F_8 ( V_1 , & V_3 -> V_43 ) ;
return F_9 ( V_1 , V_18 ) ;
}
static void F_22 ( struct V_1 * V_1 , int V_30 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
T_2 V_44 ;
T_2 V_45 ;
unsigned int V_46 ;
unsigned char * V_47 ;
T_1 V_38 ;
void (* F_23) ( struct V_1 * );
int V_37 ;
F_2 ( L_1 , V_7 ) ;
if ( V_30 & V_48 ) {
V_44 = V_3 -> V_49 -> V_50 ;
V_46 = F_24 ( V_3 -> V_25 , V_44 ) ;
V_47 = V_3 -> V_51 ;
V_38 = F_20 ( V_3 -> V_49 -> V_40 ) ;
F_23 = F_7 ;
V_37 = V_3 -> V_49 -> V_28 ;
} else {
V_45 = V_3 -> V_27 -> V_50 ;
V_46 = F_19 ( V_3 -> V_25 , V_45 ) ;
V_47 = V_3 -> V_41 ;
V_38 = F_20 ( V_3 -> V_27 -> V_40 ) ;
F_23 = F_1 ;
V_37 = V_3 -> V_27 -> V_28 ;
}
F_21 ( V_1 , V_3 -> V_25 , V_46 , V_47 , V_38 , F_23 , V_3 , V_37 ) ;
}
static void F_25 ( struct V_2 * V_3 )
{
T_2 V_45 ;
T_2 V_44 ;
unsigned int V_21 ;
unsigned int V_22 ;
T_1 V_38 ;
F_2 ( L_1 , V_7 ) ;
F_26 ( V_19 , & V_3 -> V_12 ) ;
F_26 ( V_11 , & V_3 -> V_12 ) ;
V_45 = V_3 -> V_27 -> V_50 ;
V_44 = V_3 -> V_49 -> V_50 ;
V_21 = F_13 ( V_3 -> V_25 , V_45 ) ;
V_22 = F_14 ( V_3 -> V_25 , V_44 ) ;
V_38 = F_20 ( V_3 -> V_27 -> V_40 ) ;
F_15 ( V_3 -> V_25 , V_21 , V_3 -> V_41 ,
V_38 , NULL , V_3 -> V_27 -> V_28 ) ;
F_15 ( V_3 -> V_25 , V_22 , V_3 -> V_51 , V_38 , NULL , V_29 * 10 ) ;
F_5 ( V_11 , & V_3 -> V_12 ) ;
F_5 ( V_19 , & V_3 -> V_12 ) ;
}
static int F_27 ( struct V_2 * V_3 )
{
struct V_1 * V_1 ;
int V_52 ;
F_2 ( L_1 , V_7 ) ;
if ( ! V_3 -> V_16 )
return - V_53 ;
if ( F_4 ( V_19 , & V_3 -> V_12 ) )
if ( F_28 ( V_3 -> V_20 ,
! F_4 ( V_19 ,
& V_3 -> V_12 ) ) )
return - V_54 ;
if ( V_3 -> V_55 . V_56 == V_57 ) {
F_25 ( V_3 ) ;
return 0 ;
}
V_1 = F_18 ( 0 , V_18 ) ;
if ( ! V_1 )
return - V_39 ;
V_1 -> V_4 = V_3 ;
F_22 ( V_1 , V_48 ) ;
F_26 ( V_15 , & V_3 -> V_12 ) ;
F_26 ( V_19 , & V_3 -> V_12 ) ;
F_8 ( V_1 , & V_3 -> V_17 ) ;
V_52 = F_9 ( V_1 , V_18 ) ;
if ( ! V_52 )
goto exit;
F_5 ( V_15 , & V_3 -> V_12 ) ;
F_11 ( V_1 ) ;
exit:
F_29 ( V_1 ) ;
return V_52 ;
}
static int F_30 ( struct V_2 * V_3 , int V_58 )
{
struct V_1 * V_1 ;
int V_52 ;
F_2 ( L_1 , V_7 ) ;
if ( ! V_3 -> V_16 )
return - V_53 ;
if ( F_4 ( V_11 , & V_3 -> V_12 ) )
if ( F_28 ( V_3 -> V_13 ,
! F_4 ( V_11 ,
& V_3 -> V_12 ) ) )
return - V_54 ;
if ( V_3 -> V_55 . V_56 == V_57 ) {
V_3 -> V_41 [ 0 ] = V_58 ;
F_25 ( V_3 ) ;
return 0 ;
}
V_1 = F_18 ( 0 , V_18 ) ;
if ( ! V_1 )
return - V_39 ;
V_1 -> V_4 = V_3 ;
F_22 ( V_1 , V_59 ) ;
F_26 ( V_11 , & V_3 -> V_12 ) ;
F_8 ( V_1 , & V_3 -> V_43 ) ;
V_3 -> V_41 [ 0 ] = V_58 ;
V_52 = F_9 ( V_1 , V_18 ) ;
if ( ! V_52 )
goto exit;
F_5 ( V_11 , & V_3 -> V_12 ) ;
F_11 ( V_1 ) ;
exit:
F_29 ( V_1 ) ;
return V_52 ;
}
static int F_31 ( struct V_2 * V_3 , int V_60 )
{
if ( ! V_3 )
return - V_61 ;
if ( ! V_3 -> V_62 )
return - V_53 ;
if ( ! V_3 -> V_63 )
return - V_53 ;
if ( V_60 & V_64 ) {
if ( F_4 ( V_19 , & V_3 -> V_12 ) )
return - V_65 ;
}
if ( V_60 & V_66 ) {
if ( F_4 ( V_11 , & V_3 -> V_12 ) )
return - V_65 ;
}
return 0 ;
}
static int F_32 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_72 , unsigned int * V_73 )
{
struct V_2 * V_3 = V_68 -> V_74 ;
int V_75 ;
int V_76 [ 2 ] ;
int V_77 ;
F_2 ( L_1 , V_7 ) ;
V_77 = F_31 ( V_3 , V_64 ) ;
if ( V_77 )
return V_77 ;
F_33 ( & V_3 -> V_78 ) ;
V_75 = F_34 ( V_72 -> V_79 ) ;
switch ( V_3 -> V_55 . V_56 ) {
case V_80 :
if ( ! V_75 )
V_76 [ 0 ] = V_81 ;
else
V_76 [ 0 ] = V_82 ;
break;
case V_57 :
V_76 [ 0 ] = V_83 ;
V_76 [ 1 ] = V_84 ;
V_3 -> V_41 [ 0 ] = V_85 ;
V_3 -> V_41 [ V_86 ] = V_75 ;
break;
}
for ( V_77 = 0 ; V_77 < V_72 -> V_77 ; V_77 ++ ) {
if ( F_27 ( V_3 ) )
break;
if ( V_3 -> V_55 . V_56 == V_80 ) {
V_73 [ V_77 ] = V_3 -> V_51 [ V_76 [ 0 ] ] ;
continue;
}
V_73 [ V_77 ] = V_3 -> V_51 [ V_76 [ 0 ] ] + 256 *
V_3 -> V_51 [ V_76 [ 1 ] ] ;
}
F_35 ( & V_3 -> V_78 ) ;
return V_77 ;
}
static int F_36 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_72 , unsigned int * V_73 )
{
struct V_2 * V_3 = V_68 -> V_74 ;
int V_75 ;
int V_58 ;
int V_76 ;
int V_77 ;
F_2 ( L_1 , V_7 ) ;
V_77 = F_31 ( V_3 , V_66 ) ;
if ( V_77 )
return V_77 ;
F_33 ( & V_3 -> V_78 ) ;
V_75 = F_34 ( V_72 -> V_79 ) ;
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
if ( F_30 ( V_3 , V_58 ) )
break;
}
F_35 ( & V_3 -> V_78 ) ;
return V_77 ;
}
static int F_37 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_72 , unsigned int * V_73 )
{
struct V_2 * V_3 = V_68 -> V_74 ;
int V_75 ;
int V_76 ;
int V_77 ;
F_2 ( L_1 , V_7 ) ;
V_77 = F_31 ( V_3 , V_64 ) ;
if ( V_77 )
return V_77 ;
F_33 ( & V_3 -> V_78 ) ;
V_75 = F_34 ( V_72 -> V_79 ) ;
V_76 = V_91 - 1 ;
V_3 -> V_41 [ 0 ] = V_92 ;
for ( V_77 = 0 ; V_77 < V_72 -> V_77 ; V_77 ++ ) {
if ( F_27 ( V_3 ) )
break;
V_73 [ V_77 ] = V_3 -> V_51 [ V_76 + V_75 ] ;
}
F_35 ( & V_3 -> V_78 ) ;
return V_77 ;
}
static int F_38 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_72 , unsigned int * V_73 )
{
struct V_2 * V_3 = V_68 -> V_74 ;
unsigned char * V_93 ;
int V_76 ;
int V_52 ;
F_2 ( L_1 , V_7 ) ;
V_52 = F_31 ( V_3 , V_64 ) ;
if ( V_52 )
return V_52 ;
F_33 ( & V_3 -> V_78 ) ;
V_93 = V_3 -> V_51 ;
if ( V_3 -> V_55 . V_56 == V_57 ) {
V_76 = V_94 ;
V_3 -> V_41 [ 0 ] = V_95 ;
} else {
V_76 = V_96 ;
}
V_52 = F_27 ( V_3 ) ;
if ( ! V_52 ) {
if ( V_3 -> V_55 . V_56 == V_80 )
V_73 [ 1 ] = ( ( ( V_93 [ V_76 ] >> 4 ) & 0x03 ) |
( ( V_93 [ V_76 ] << 2 ) & 0x04 ) |
( ( V_93 [ V_76 ] >> 3 ) & 0x18 ) ) ;
else
V_73 [ 1 ] = V_93 [ V_76 ] ;
V_52 = 2 ;
}
F_35 ( & V_3 -> V_78 ) ;
return V_52 ;
}
static int F_39 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_72 , unsigned int * V_73 )
{
struct V_2 * V_3 = V_68 -> V_74 ;
int V_75 ;
unsigned char * V_93 ;
int V_76 ;
int V_97 ;
int V_77 ;
F_2 ( L_1 , V_7 ) ;
V_77 = F_31 ( V_3 , V_64 ) ;
if ( V_77 )
return V_77 ;
F_33 ( & V_3 -> V_78 ) ;
V_75 = F_34 ( V_72 -> V_79 ) ;
V_93 = V_3 -> V_51 ;
if ( V_3 -> V_55 . V_56 == V_57 ) {
V_76 = V_94 ;
V_3 -> V_41 [ 0 ] = V_95 ;
} else {
V_76 = V_96 ;
}
for ( V_77 = 0 ; V_77 < V_72 -> V_77 ; V_77 ++ ) {
if ( F_27 ( V_3 ) )
break;
if ( V_3 -> V_55 . V_56 == V_80 )
V_97 = ( ( ( V_93 [ V_76 ] >> 4 ) & 0x03 ) |
( ( V_93 [ V_76 ] << 2 ) & 0x04 ) |
( ( V_93 [ V_76 ] >> 3 ) & 0x18 ) ) ;
else
V_97 = V_93 [ V_76 ] ;
V_73 [ V_77 ] = ( V_97 >> V_75 ) & 1 ;
}
F_35 ( & V_3 -> V_78 ) ;
return V_77 ;
}
static int F_40 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_72 , unsigned int * V_73 )
{
struct V_2 * V_3 = V_68 -> V_74 ;
int V_75 ;
unsigned char * V_98 ;
int V_76 ;
int V_58 ;
int V_77 ;
F_2 ( L_1 , V_7 ) ;
V_77 = F_31 ( V_3 , V_66 ) ;
if ( V_77 )
return V_77 ;
F_33 ( & V_3 -> V_78 ) ;
V_75 = F_34 ( V_72 -> V_79 ) ;
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
if ( F_30 ( V_3 , V_58 ) )
break;
}
F_35 ( & V_3 -> V_78 ) ;
return V_77 ;
}
static int F_41 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_72 , unsigned int * V_73 )
{
struct V_2 * V_3 = V_68 -> V_74 ;
int V_75 ;
int V_76 ;
int V_77 ;
F_2 ( L_1 , V_7 ) ;
V_77 = F_31 ( V_3 , V_64 ) ;
if ( V_77 )
return V_77 ;
F_33 ( & V_3 -> V_78 ) ;
V_75 = F_34 ( V_72 -> V_79 ) ;
V_76 = V_100 ;
V_3 -> V_41 [ 0 ] = V_103 ;
for ( V_77 = 0 ; V_77 < V_72 -> V_77 ; V_77 ++ ) {
if ( F_27 ( V_3 ) )
break;
V_73 [ V_77 ] = ( V_3 -> V_51 [ V_76 ] >> V_75 ) & 1 ;
}
F_35 ( & V_3 -> V_78 ) ;
return V_77 ;
}
static int F_42 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_72 , unsigned int * V_73 )
{
struct V_2 * V_3 = V_68 -> V_74 ;
unsigned char * V_93 , * V_98 ;
int V_60 , V_76 , V_58 ;
int V_52 ;
F_2 ( L_1 , V_7 ) ;
V_60 = 0 ;
if ( V_73 [ 0 ] )
V_60 |= V_66 ;
if ( V_3 -> V_55 . V_56 == V_57 )
V_60 |= V_64 ;
V_52 = F_31 ( V_3 , V_60 ) ;
if ( V_52 )
return V_52 ;
F_33 ( & V_3 -> V_78 ) ;
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
V_52 = F_30 ( V_3 , V_58 ) ;
if ( V_52 )
goto V_105;
}
if ( V_3 -> V_55 . V_56 == V_57 ) {
V_76 = V_100 ;
V_98 [ 0 ] = V_103 ;
V_52 = F_27 ( V_3 ) ;
if ( ! V_52 ) {
V_73 [ 1 ] = V_93 [ V_76 ] ;
V_52 = 2 ;
}
} else {
V_73 [ 1 ] = V_98 [ V_76 ] ;
V_52 = 2 ;
}
V_105:
F_35 ( & V_3 -> V_78 ) ;
return V_52 ;
}
static int F_43 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_72 , unsigned int * V_73 )
{
struct V_2 * V_3 = V_68 -> V_74 ;
int V_75 ;
int V_76 [ 2 ] ;
int V_77 ;
F_2 ( L_1 , V_7 ) ;
V_77 = F_31 ( V_3 , V_64 ) ;
if ( V_77 )
return V_77 ;
F_33 ( & V_3 -> V_78 ) ;
V_75 = F_34 ( V_72 -> V_79 ) ;
switch ( V_3 -> V_55 . V_56 ) {
case V_80 :
if ( ! V_75 )
V_76 [ 0 ] = V_106 ;
else
V_76 [ 0 ] = V_107 ;
break;
case V_57 :
V_76 [ 0 ] = V_108 ;
V_76 [ 1 ] = V_108 ;
V_3 -> V_41 [ 0 ] = V_109 ;
break;
}
for ( V_77 = 0 ; V_77 < V_72 -> V_77 ; V_77 ++ ) {
if ( F_27 ( V_3 ) )
break;
if ( V_3 -> V_55 . V_56 == V_80 )
V_73 [ V_77 ] = V_3 -> V_51 [ V_76 [ 0 ] ] ;
else
V_73 [ V_77 ] = V_3 -> V_51 [ V_76 [ 0 ] * ( V_75 + 1 ) + 1 ]
+ 256 * V_3 -> V_51 [ V_76 [ 1 ] * 2 + 2 ] ;
}
F_35 ( & V_3 -> V_78 ) ;
return V_77 ;
}
static int F_44 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_72 , unsigned int * V_73 )
{
struct V_2 * V_3 = V_68 -> V_74 ;
unsigned int V_110 ;
int V_75 ;
int V_58 ;
int V_76 ;
int V_77 ;
F_2 ( L_1 , V_7 ) ;
V_77 = F_31 ( V_3 , V_66 ) ;
if ( V_77 )
return V_77 ;
F_33 ( & V_3 -> V_78 ) ;
V_110 = V_73 [ 0 ] ;
if ( V_110 != V_111 && V_110 != V_112 )
return - V_113 ;
V_75 = F_34 ( V_72 -> V_79 ) ;
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
if ( F_30 ( V_3 , V_58 ) )
break;
F_35 ( & V_3 -> V_78 ) ;
return V_77 ;
}
static int F_45 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_72 , unsigned int * V_73 )
{
struct V_2 * V_3 = V_68 -> V_74 ;
unsigned long V_117 ;
unsigned long V_118 ;
int V_75 ;
int V_58 ;
int V_77 ;
F_2 ( L_1 , V_7 ) ;
V_77 = F_31 ( V_3 , V_66 ) ;
if ( V_77 )
return V_77 ;
F_33 ( & V_3 -> V_78 ) ;
V_75 = F_34 ( V_72 -> V_79 ) ;
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
V_118 = F_46 ( V_117 * 1000 / 115 ) ;
if ( ( ( V_118 + 1 ) * V_118 ) < V_117 * 1000 / 115 )
V_118 += 1 ;
V_3 -> V_41 [ 6 + V_75 ] = V_118 ;
if ( F_30 ( V_3 , V_58 ) )
break;
}
F_35 ( & V_3 -> V_78 ) ;
return V_77 ;
}
static int F_47 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_72 , unsigned int * V_73 )
{
struct V_2 * V_3 = V_68 -> V_74 ;
int V_76 [ 2 ] ;
int V_77 ;
F_2 ( L_1 , V_7 ) ;
V_77 = F_31 ( V_3 , V_64 ) ;
if ( V_77 )
return V_77 ;
F_33 ( & V_3 -> V_78 ) ;
V_76 [ 0 ] = V_121 ;
V_76 [ 1 ] = V_122 ;
V_3 -> V_41 [ 0 ] = V_123 ;
for ( V_77 = 0 ; V_77 < V_72 -> V_77 ; V_77 ++ ) {
if ( F_27 ( V_3 ) )
break;
V_73 [ V_77 ] = V_3 -> V_51 [ V_76 [ 0 ] ] + 4 * V_3 -> V_51 [ V_76 [ 1 ] ] ;
}
F_35 ( & V_3 -> V_78 ) ;
return V_77 ;
}
static int F_48 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_72 , unsigned int * V_73 )
{
struct V_2 * V_3 = V_68 -> V_74 ;
unsigned char * V_98 ;
int V_76 [ 2 ] ;
int V_58 ;
int V_77 ;
F_2 ( L_1 , V_7 ) ;
V_77 = F_31 ( V_3 , V_66 ) ;
if ( V_77 )
return V_77 ;
F_33 ( & V_3 -> V_78 ) ;
V_98 = V_3 -> V_41 ;
V_76 [ 0 ] = V_121 ;
V_76 [ 1 ] = V_122 ;
V_58 = V_124 ;
for ( V_77 = 0 ; V_77 < V_72 -> V_77 ; V_77 ++ ) {
V_98 [ V_76 [ 0 ] ] = ( unsigned char ) ( V_73 [ V_77 ] & 0x03 ) ;
V_98 [ V_76 [ 1 ] ] = ( unsigned char ) ( V_73 [ V_77 ] >> 2 ) & 0xff ;
if ( F_30 ( V_3 , V_58 ) )
break;
}
F_35 ( & V_3 -> V_78 ) ;
return V_77 ;
}
static int F_49 ( struct V_67 * V_68 ,
struct V_125 * V_126 )
{
int V_127 ;
struct V_2 * V_3 ;
int V_128 ;
struct V_69 * V_70 ;
int V_129 ;
F_2 ( L_1 , V_7 ) ;
F_50 ( & V_130 ) ;
for ( V_127 = 0 ; V_127 < V_131 ; V_127 ++ )
if ( V_132 [ V_127 ] . V_62 && ! V_132 [ V_127 ] . V_63 )
break;
if ( V_127 == V_131 ) {
F_51 ( & V_130 ) ;
return - V_53 ;
}
V_3 = & V_132 [ V_127 ] ;
F_33 ( & V_3 -> V_78 ) ;
V_68 -> V_133 = V_3 -> V_55 . V_134 ;
V_68 -> V_74 = V_3 ;
if ( V_3 -> V_55 . V_56 == V_80 )
V_128 = 5 ;
else
V_128 = 6 ;
if ( F_52 ( V_68 , V_128 ) < 0 ) {
F_35 ( & V_3 -> V_78 ) ;
F_51 ( & V_130 ) ;
return - V_39 ;
}
V_70 = V_68 -> V_135 + V_136 ;
V_70 -> type = V_137 ;
V_70 -> V_138 = V_139 | V_140 ;
V_70 -> V_141 = V_3 -> V_55 . V_142 ;
V_70 -> V_143 = ( 1 << V_3 -> V_55 . V_144 ) - 1 ;
V_70 -> V_145 = V_3 -> V_55 . V_146 ;
V_70 -> V_147 = F_32 ;
V_70 = V_68 -> V_135 + V_148 ;
V_70 -> type = V_149 ;
V_70 -> V_138 = V_150 | V_140 ;
V_70 -> V_141 = V_3 -> V_55 . V_151 ;
V_70 -> V_143 = ( 1 << V_3 -> V_55 . V_152 ) - 1 ;
V_70 -> V_145 = V_3 -> V_55 . V_146 ;
V_70 -> V_153 = F_36 ;
if ( V_3 -> V_55 . V_56 == V_57 ) {
V_70 -> V_138 |= V_139 ;
V_70 -> V_147 = F_37 ;
}
V_70 = V_68 -> V_135 + V_154 ;
V_70 -> type = V_155 ;
V_70 -> V_138 = V_139 | V_140 ;
V_70 -> V_141 = V_3 -> V_55 . V_156 ;
V_70 -> V_143 = 1 ;
V_70 -> V_147 = F_39 ;
V_70 -> V_157 = F_38 ;
V_70 = V_68 -> V_135 + V_158 ;
V_70 -> type = V_159 ;
V_70 -> V_138 = V_150 | V_140 ;
V_70 -> V_141 = V_3 -> V_55 . V_160 ;
V_70 -> V_143 = 1 ;
V_70 -> V_153 = F_40 ;
V_70 -> V_157 = F_42 ;
if ( V_3 -> V_55 . V_56 == V_57 ) {
V_70 -> V_138 |= V_139 ;
V_70 -> V_147 = F_41 ;
}
V_70 = V_68 -> V_135 + V_161 ;
V_70 -> type = V_162 ;
V_70 -> V_138 = V_139 ;
V_70 -> V_141 = V_3 -> V_55 . V_163 ;
V_70 -> V_147 = F_43 ;
V_70 -> V_164 = F_44 ;
if ( V_3 -> V_55 . V_56 == V_80 ) {
V_70 -> V_138 |= V_150 ;
V_70 -> V_143 = ( 1 << V_3 -> V_55 . V_165 ) - 1 ;
V_70 -> V_153 = F_45 ;
}
if ( V_3 -> V_55 . V_56 == V_57 ) {
V_70 = V_68 -> V_135 + V_166 ;
V_70 -> type = V_167 ;
V_70 -> V_138 = V_139 | V_150 ;
V_70 -> V_141 = V_3 -> V_55 . V_168 ;
V_70 -> V_143 = ( 1 << V_3 -> V_55 . V_169 ) - 1 ;
V_70 -> V_147 = F_47 ;
V_70 -> V_153 = F_48 ;
}
V_3 -> V_63 = 1 ;
V_129 = V_68 -> V_129 ;
F_53 ( V_170
L_4 ,
V_129 , V_3 -> V_171 , V_3 -> V_55 . V_134 ) ;
F_35 ( & V_3 -> V_78 ) ;
F_51 ( & V_130 ) ;
return 0 ;
}
static int F_54 ( struct V_67 * V_68 )
{
struct V_2 * V_3 ;
int V_129 ;
F_2 ( L_1 , V_7 ) ;
if ( ! V_68 )
return - V_61 ;
V_3 = V_68 -> V_74 ;
if ( ! V_3 )
return - V_61 ;
F_33 ( & V_3 -> V_78 ) ;
V_68 -> V_74 = NULL ;
V_3 -> V_63 = 0 ;
V_129 = V_68 -> V_129 ;
F_53 ( V_170
L_5 ,
V_129 , V_3 -> V_171 , V_3 -> V_55 . V_134 ) ;
F_35 ( & V_3 -> V_78 ) ;
return 0 ;
}
static int F_55 ( struct V_172 * V_16 ,
const struct V_173 * V_174 )
{
int V_127 ;
struct V_2 * V_3 ;
struct V_175 * V_176 ;
struct V_177 * V_178 ;
T_1 V_38 ;
F_2 ( L_1 , V_7 ) ;
F_50 ( & V_130 ) ;
for ( V_127 = 0 ; V_127 < V_131 ; V_127 ++ )
if ( ! V_132 [ V_127 ] . V_62 )
break;
if ( V_127 == V_131 ) {
F_51 ( & V_130 ) ;
return - V_179 ;
}
V_3 = & V_132 [ V_127 ] ;
memset ( V_3 , 0x00 , sizeof( struct V_2 ) ) ;
V_3 -> V_171 = V_127 ;
V_176 = V_16 -> V_180 ;
if ( V_176 -> V_181 . V_182 != 2 )
goto error;
for ( V_127 = 0 ; V_127 < V_176 -> V_181 . V_182 ; V_127 ++ ) {
V_178 = & V_176 -> V_183 [ V_127 ] . V_181 ;
if ( F_56 ( V_178 ) ) {
V_3 -> V_49 = V_178 ;
continue;
}
if ( F_57 ( V_178 ) ) {
V_3 -> V_27 = V_178 ;
continue;
}
if ( F_58 ( V_178 ) ) {
V_3 -> V_49 = V_178 ;
continue;
}
if ( F_59 ( V_178 ) ) {
V_3 -> V_27 = V_178 ;
continue;
}
}
if ( ! V_3 -> V_49 || ! V_3 -> V_27 )
goto error;
V_38 = F_20 ( V_3 -> V_49 -> V_40 ) ;
V_3 -> V_51 = F_60 ( V_38 , V_18 ) ;
if ( ! V_3 -> V_51 ) {
F_51 ( & V_130 ) ;
return - V_39 ;
}
V_38 = F_20 ( V_3 -> V_27 -> V_40 ) ;
V_3 -> V_41 = F_60 ( V_38 , V_18 ) ;
if ( ! V_3 -> V_41 ) {
F_61 ( V_3 -> V_51 ) ;
F_51 ( & V_130 ) ;
return - V_39 ;
}
V_3 -> V_25 = F_62 ( V_16 ) ;
V_3 -> V_16 = V_16 ;
F_63 ( & V_3 -> V_78 , 8 ) ;
F_64 ( & V_3 -> V_20 ) ;
F_64 ( & V_3 -> V_13 ) ;
F_65 ( & V_3 -> V_17 ) ;
F_65 ( & V_3 -> V_43 ) ;
F_66 ( V_16 , V_3 ) ;
switch ( V_174 -> V_184 ) {
case V_185 :
V_3 -> V_55 . V_134 = L_6 ;
V_3 -> V_55 . V_56 = V_80 ;
V_3 -> V_55 . V_146 = & V_186 ;
V_3 -> V_55 . V_142 = 2 ;
V_3 -> V_55 . V_144 = 8 ;
V_3 -> V_55 . V_151 = 2 ;
V_3 -> V_55 . V_152 = 8 ;
V_3 -> V_55 . V_156 = 5 ;
V_3 -> V_55 . V_187 = 1 ;
V_3 -> V_55 . V_160 = 8 ;
V_3 -> V_55 . V_188 = 1 ;
V_3 -> V_55 . V_163 = 2 ;
V_3 -> V_55 . V_165 = 16 ;
V_3 -> V_55 . V_168 = 0 ;
V_3 -> V_55 . V_169 = 0 ;
break;
case V_189 :
V_3 -> V_55 . V_134 = L_7 ;
V_3 -> V_55 . V_56 = V_57 ;
V_3 -> V_55 . V_146 = & V_190 ;
V_3 -> V_55 . V_142 = 8 ;
V_3 -> V_55 . V_144 = 10 ;
V_3 -> V_55 . V_151 = 8 ;
V_3 -> V_55 . V_152 = 8 ;
V_3 -> V_55 . V_156 = 8 ;
V_3 -> V_55 . V_187 = 1 ;
V_3 -> V_55 . V_160 = 8 ;
V_3 -> V_55 . V_188 = 1 ;
V_3 -> V_55 . V_163 = 2 ;
V_3 -> V_55 . V_165 = 0 ;
V_3 -> V_55 . V_168 = 1 ;
V_3 -> V_55 . V_169 = 10 ;
break;
}
if ( V_3 -> V_55 . V_56 == V_57 ) {
F_16 ( V_3 , V_33 ) ;
F_53 ( V_170 L_8 , V_3 -> V_34 . V_35 ) ;
if ( F_12 ( V_3 ) ) {
F_16 ( V_3 , V_191 ) ;
F_53 ( V_170 L_8 ,
V_3 -> V_34 . V_36 ) ;
} else {
F_3 ( L_9 ) ;
}
}
if ( V_3 -> V_55 . V_56 == V_80 )
F_17 ( V_3 ) ;
V_3 -> V_62 = 1 ;
F_53 ( V_170 L_10 ,
V_3 -> V_171 , V_3 -> V_55 . V_134 ) ;
F_51 ( & V_130 ) ;
F_67 ( V_3 -> V_25 , V_192 ) ;
return 0 ;
error:
F_51 ( & V_130 ) ;
return - V_53 ;
}
static void F_68 ( struct V_172 * V_16 )
{
struct V_2 * V_3 = F_69 ( V_16 ) ;
F_2 ( L_1 , V_7 ) ;
if ( ! V_3 )
return;
F_70 ( V_3 -> V_25 ) ;
F_50 ( & V_130 ) ;
F_33 ( & V_3 -> V_78 ) ;
V_3 -> V_62 = 0 ;
F_66 ( V_3 -> V_16 , NULL ) ;
F_71 ( & V_3 -> V_17 ) ;
F_71 ( & V_3 -> V_43 ) ;
F_61 ( V_3 -> V_51 ) ;
F_61 ( V_3 -> V_41 ) ;
F_53 ( V_170 L_11 ,
V_3 -> V_171 , V_3 -> V_55 . V_134 ) ;
F_35 ( & V_3 -> V_78 ) ;
F_51 ( & V_130 ) ;
}
static int T_3 F_72 ( void )
{
int V_52 ;
F_53 ( V_170 L_12
L_13 ) ;
V_52 = F_73 ( & V_193 ) ;
if ( V_52 < 0 )
return V_52 ;
return F_74 ( & V_194 ) ;
}
static void T_4 F_75 ( void )
{
F_76 ( & V_193 ) ;
F_77 ( & V_194 ) ;
}
