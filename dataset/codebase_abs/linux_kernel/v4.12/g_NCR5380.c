static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_5 ,
F_4 ( F_5 ( V_6 ) & V_7 ) ) ;
F_3 ( V_8 , V_4 -> V_9 ) ;
F_3 ( V_10 , V_4 -> V_9 ) ;
F_3 ( V_11 ,
V_12 | V_13 | V_14 ) ;
F_6 ( 1 ) ;
F_3 ( V_11 , V_12 ) ;
F_3 ( V_8 , 0 ) ;
F_3 ( V_5 , 0 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_15 , V_16 ;
F_5 ( V_17 ) ;
V_15 = F_8 () ;
F_1 ( V_2 ) ;
V_16 = F_9 ( V_15 ) ;
F_5 ( V_17 ) ;
if ( V_16 <= 0 )
return V_18 ;
return V_16 ;
}
static void F_10 ( int V_19 , T_1 V_16 , T_1 V_20 [] )
{
T_1 V_21 = 0 ;
F_11 ( V_20 [ 0 ] , 0x779 ) ;
F_11 ( V_20 [ 1 ] , 0x379 ) ;
F_11 ( V_20 [ 2 ] , 0x379 ) ;
F_11 ( V_20 [ 3 ] , 0x379 ) ;
F_11 ( V_20 [ 4 ] , 0x379 ) ;
if ( V_16 == 9 )
V_16 = 2 ;
if ( V_19 >= 0 && V_19 <= 7 )
V_21 = 0x80 | V_19 | ( V_16 << 4 ) ;
F_11 ( V_21 , 0x379 ) ;
}
static T_2 F_12 ( int V_16 , void * V_22 )
{
return V_23 ;
}
static int F_13 ( int * V_24 )
{
while ( * V_24 != - 1 ) {
if ( ! F_14 ( * V_24 , F_12 ,
V_25 , L_1 ,
( void * ) V_24 ) ) {
F_15 ( * V_24 , ( void * ) V_24 ) ;
return * V_24 ;
}
V_24 ++ ;
}
return - 1 ;
}
static int F_16 ( struct V_26 * V_27 ,
struct V_28 * V_29 , int V_30 , int V_16 , int V_31 )
{
bool V_32 = V_30 <= 0xffff ;
int V_33 ;
int V_34 = 0 ;
unsigned int * V_35 = NULL ;
T_1 * V_20 = NULL ;
int V_36 ;
int V_37 = - 1 ;
unsigned long V_38 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_1 T_3 * V_39 ;
switch ( V_31 ) {
case V_40 :
V_34 = V_41 | V_42 ;
break;
case V_43 :
V_35 = V_44 ;
V_20 = V_45 ;
break;
case V_46 :
V_35 = V_44 ;
V_20 = V_47 ;
break;
case V_48 :
V_35 = V_49 ;
V_20 = V_45 ;
break;
}
if ( V_32 && V_35 && V_20 ) {
F_10 ( - 1 , 0 , V_20 ) ;
V_38 = 16 ;
if ( V_30 )
for ( V_36 = 0 ; V_35 [ V_36 ] ; V_36 ++ ) {
if ( V_30 == V_35 [ V_36 ] ) {
if ( ! F_17 ( V_35 [ V_36 ] ,
V_38 ,
L_2 ) )
return - V_50 ;
break;
}
}
else
for ( V_36 = 0 ; V_35 [ V_36 ] ; V_36 ++ ) {
if ( ! F_17 ( V_35 [ V_36 ] , V_38 ,
L_2 ) )
continue;
if ( F_18 ( V_35 [ V_36 ] ) == 0xff )
break;
F_19 ( V_35 [ V_36 ] , V_38 ) ;
}
if ( V_35 [ V_36 ] ) {
F_10 ( V_36 , 0 , V_20 ) ;
V_30 = V_35 [ V_36 ] ;
F_11 ( 0xc0 , V_30 + 9 ) ;
if ( F_18 ( V_30 + 9 ) != 0x80 ) {
V_33 = - V_51 ;
goto V_52;
}
V_37 = V_36 ;
} else
return - V_53 ;
} else if ( V_32 ) {
V_38 = 8 ;
if ( ! V_30 || ! F_17 ( V_30 , V_38 , L_3 ) )
return - V_50 ;
} else {
V_38 = V_54 ;
if ( ! F_20 ( V_30 , V_38 , L_3 ) )
return - V_50 ;
}
if ( V_32 )
V_39 = F_21 ( V_30 , V_38 ) ;
else
V_39 = F_22 ( V_30 , V_38 ) ;
if ( ! V_39 ) {
V_33 = - V_55 ;
goto V_52;
}
V_2 = F_23 ( V_27 , sizeof( struct V_3 ) ) ;
if ( V_2 == NULL ) {
V_33 = - V_55 ;
goto V_56;
}
V_4 = F_2 ( V_2 ) ;
V_4 -> V_57 = V_39 ;
V_4 -> V_38 = V_38 ;
if ( V_32 ) {
V_4 -> V_58 = V_30 ;
V_4 -> V_59 = 1 ;
V_4 -> V_60 = 0 ;
switch ( V_31 ) {
case V_61 :
V_4 -> V_58 += 8 ;
V_4 -> V_62 = 0 ;
V_4 -> V_63 = 1 ;
V_4 -> V_64 = 4 ;
break;
case V_48 :
V_4 -> V_59 = 2 ;
case V_43 :
case V_46 :
V_4 -> V_62 = 9 ;
V_4 -> V_63 = 10 ;
V_4 -> V_64 = 8 ;
break;
}
} else {
V_4 -> V_30 = V_30 ;
V_4 -> V_60 = V_65 ;
switch ( V_31 ) {
case V_61 :
V_4 -> V_62 = 0x100 ;
V_4 -> V_63 = 0x101 ;
V_4 -> V_64 = 0x104 ;
break;
case V_48 :
case V_43 :
case V_46 :
F_24 ( V_66 L_4 ) ;
V_33 = - V_53 ;
goto V_67;
}
}
F_3 ( V_68 , 0 ) ;
if ( F_5 ( V_68 ) != 0 ) {
V_33 = - V_51 ;
goto V_67;
}
V_33 = F_25 ( V_2 , V_34 | V_69 ) ;
if ( V_33 )
goto V_67;
switch ( V_31 ) {
case V_61 :
case V_48 :
case V_43 :
case V_46 :
F_3 ( V_4 -> V_62 , V_70 ) ;
}
F_26 ( V_2 ) ;
if ( V_16 == 255 || V_16 == 0 )
V_16 = V_18 ;
else if ( V_16 == - 1 )
V_16 = V_71 ;
if ( V_31 == V_46 ) {
int * V_24 = V_72 ;
int V_73 = - 1 ;
switch ( V_16 ) {
case V_18 :
V_73 = 0 ;
break;
case V_71 :
V_73 = F_13 ( V_24 ) ;
break;
default:
while ( * V_24 != - 1 )
if ( * V_24 ++ == V_16 )
V_73 = V_16 ;
}
if ( V_73 <= 0 ) {
V_73 = 0 ;
V_16 = V_18 ;
}
F_10 ( V_37 , V_73 , V_20 ) ;
}
if ( V_16 == V_71 ) {
V_2 -> V_16 = F_7 ( V_2 ) ;
if ( V_2 -> V_16 == V_18 )
F_27 ( V_74 , V_2 , L_5 ) ;
} else {
V_2 -> V_16 = V_16 ;
if ( V_2 -> V_16 == V_18 )
F_27 ( V_74 , V_2 , L_6 ) ;
}
if ( V_2 -> V_16 != V_18 ) {
if ( F_14 ( V_2 -> V_16 , V_75 ,
0 , L_7 , V_2 ) ) {
V_2 -> V_16 = V_18 ;
F_27 ( V_74 , V_2 ,
L_8 , V_2 -> V_16 ) ;
} else {
F_27 ( V_74 , V_2 ,
L_9 , V_2 -> V_16 ) ;
}
}
V_33 = F_28 ( V_2 , V_29 ) ;
if ( V_33 )
goto V_76;
F_29 ( V_2 ) ;
F_30 ( V_29 , V_2 ) ;
return 0 ;
V_76:
if ( V_2 -> V_16 != V_18 )
F_15 ( V_2 -> V_16 , V_2 ) ;
F_31 ( V_2 ) ;
V_67:
F_32 ( V_2 ) ;
V_56:
F_33 ( V_39 ) ;
V_52:
if ( V_32 )
F_19 ( V_30 , V_38 ) ;
else
F_34 ( V_30 , V_38 ) ;
return V_33 ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_3 * V_39 = V_4 -> V_57 ;
unsigned long V_58 = V_4 -> V_58 ;
unsigned long V_30 = V_4 -> V_30 ;
unsigned long V_38 = V_4 -> V_38 ;
F_36 ( V_2 ) ;
if ( V_2 -> V_16 != V_18 )
F_15 ( V_2 -> V_16 , V_2 ) ;
F_31 ( V_2 ) ;
F_32 ( V_2 ) ;
F_33 ( V_39 ) ;
if ( V_58 )
F_19 ( V_58 , V_38 ) ;
else
F_34 ( V_30 , V_38 ) ;
}
static inline int F_37 ( struct V_3 * V_4 ,
unsigned char * V_77 , int V_78 )
{
int V_79 = V_78 / 128 ;
int V_80 = 0 ;
F_3 ( V_4 -> V_62 , V_70 | V_81 ) ;
F_3 ( V_4 -> V_63 , V_79 ) ;
while ( 1 ) {
if ( F_5 ( V_4 -> V_63 ) == 0 )
break;
if ( F_5 ( V_4 -> V_62 ) & V_82 ) {
F_38 ( V_83 L_10 , V_80 , V_79 ) ;
return - 1 ;
}
while ( F_5 ( V_4 -> V_62 ) & V_84 )
;
if ( V_4 -> V_58 && V_4 -> V_59 == 2 )
F_39 ( V_4 -> V_58 + V_4 -> V_64 ,
V_77 + V_80 , 64 ) ;
else if ( V_4 -> V_58 )
F_40 ( V_4 -> V_58 + V_4 -> V_64 ,
V_77 + V_80 , 128 ) ;
else
F_41 ( V_77 + V_80 ,
V_4 -> V_57 + V_85 , 128 ) ;
V_80 += 128 ;
V_79 -- ;
}
if ( V_79 ) {
while ( F_5 ( V_4 -> V_62 ) & V_84 )
;
if ( V_4 -> V_58 && V_4 -> V_59 == 2 )
F_39 ( V_4 -> V_58 + V_4 -> V_64 ,
V_77 + V_80 , 64 ) ;
else if ( V_4 -> V_58 )
F_40 ( V_4 -> V_58 + V_4 -> V_64 ,
V_77 + V_80 , 128 ) ;
else
F_41 ( V_77 + V_80 ,
V_4 -> V_57 + V_85 , 128 ) ;
V_80 += 128 ;
V_79 -- ;
}
if ( ! ( F_5 ( V_4 -> V_62 ) & V_82 ) )
F_38 ( L_11 ) ;
while ( ! ( F_5 ( V_4 -> V_62 ) & V_86 ) )
;
if ( ! ( F_5 ( V_87 ) & V_88 ) )
F_38 ( V_83 L_12 ) ;
return 0 ;
}
static inline int F_42 ( struct V_3 * V_4 ,
unsigned char * V_89 , int V_78 )
{
int V_79 = V_78 / 128 ;
int V_80 = 0 ;
F_3 ( V_4 -> V_62 , V_70 ) ;
F_3 ( V_4 -> V_63 , V_79 ) ;
while ( 1 ) {
if ( F_5 ( V_4 -> V_62 ) & V_82 ) {
F_38 ( V_83 L_13 , V_80 , V_79 ) ;
return - 1 ;
}
if ( F_5 ( V_4 -> V_63 ) == 0 )
break;
while ( F_5 ( V_4 -> V_62 ) & V_84 )
;
if ( V_4 -> V_58 && V_4 -> V_59 == 2 )
F_43 ( V_4 -> V_58 + V_4 -> V_64 ,
V_89 + V_80 , 64 ) ;
else if ( V_4 -> V_58 )
F_44 ( V_4 -> V_58 + V_4 -> V_64 ,
V_89 + V_80 , 128 ) ;
else
F_45 ( V_4 -> V_57 + V_85 ,
V_89 + V_80 , 128 ) ;
V_80 += 128 ;
V_79 -- ;
}
if ( V_79 ) {
while ( F_5 ( V_4 -> V_62 ) & V_84 )
;
if ( V_4 -> V_58 && V_4 -> V_59 == 2 )
F_43 ( V_4 -> V_58 + V_4 -> V_64 ,
V_89 + V_80 , 64 ) ;
else if ( V_4 -> V_58 )
F_44 ( V_4 -> V_58 + V_4 -> V_64 ,
V_89 + V_80 , 128 ) ;
else
F_45 ( V_4 -> V_57 + V_85 ,
V_89 + V_80 , 128 ) ;
V_80 += 128 ;
V_79 -- ;
}
while ( ! ( F_5 ( V_4 -> V_62 ) & V_86 ) ) {
F_46 ( 4 ) ;
}
if ( ! ( F_5 ( V_87 ) & V_88 ) ) {
F_38 ( V_83 L_14 ) ;
}
while ( ! ( F_5 ( V_5 ) & V_90 ) )
;
return 0 ;
}
static int F_47 ( struct V_3 * V_4 ,
struct V_91 * V_92 )
{
int V_93 = V_92 -> V_93 ;
if ( V_4 -> V_34 & V_41 )
return 0 ;
if ( V_93 > 32 * 1024 && V_92 -> V_94 . V_95 &&
! ( V_92 -> V_94 . V_95 % V_93 ) )
V_93 = 32 * 1024 ;
if ( V_93 % 128 )
V_93 = 0 ;
return V_93 ;
}
static int F_48 ( struct V_28 * V_29 , unsigned int V_96 )
{
int V_33 = F_16 ( & V_97 , V_29 , V_30 [ V_96 ] ,
V_16 [ V_96 ] , V_98 [ V_96 ] ) ;
if ( V_33 ) {
if ( V_30 [ V_96 ] )
F_38 ( V_99 L_15 ,
V_30 [ V_96 ] ) ;
return 0 ;
}
return 1 ;
}
static int F_49 ( struct V_28 * V_29 ,
unsigned int V_96 )
{
F_35 ( F_50 ( V_29 ) ) ;
F_30 ( V_29 , NULL ) ;
return 0 ;
}
static int F_51 ( struct V_100 * V_29 ,
const struct V_101 * V_102 )
{
int V_30 , V_16 ;
if ( F_52 ( V_29 ) < 0 )
return - V_50 ;
V_30 = F_53 ( V_29 , 0 ) ;
V_16 = F_54 ( V_29 , 0 ) ;
return F_16 ( & V_97 , & V_29 -> V_103 , V_30 , V_16 ,
V_102 -> V_104 ) ;
}
static void F_55 ( struct V_100 * V_29 )
{
F_35 ( F_56 ( V_29 ) ) ;
F_57 ( V_29 , NULL ) ;
}
static int T_4 F_58 ( void )
{
int V_33 = 0 ;
if ( V_16 [ 0 ] == - 1 && V_30 [ 0 ] == 0 && V_98 [ 0 ] == - 1 ) {
V_16 [ 0 ] = V_105 ;
V_30 [ 0 ] = V_106 ;
if ( V_107 )
V_98 [ 0 ] = V_40 ;
if ( V_108 )
V_98 [ 0 ] = V_61 ;
if ( V_109 )
V_98 [ 0 ] = V_43 ;
if ( V_110 )
V_98 [ 0 ] = V_48 ;
if ( V_111 )
V_98 [ 0 ] = V_46 ;
}
#ifdef F_59
if ( ! F_60 ( & V_112 ) )
V_113 = 1 ;
#endif
V_33 = F_61 ( & V_114 , V_115 ) ;
if ( ! V_33 )
V_116 = 1 ;
return ( V_113 || V_116 ) ? 0 : V_33 ;
}
static void T_5 F_62 ( void )
{
#ifdef F_59
if ( V_113 )
F_63 ( & V_112 ) ;
#endif
if ( V_116 )
F_64 ( & V_114 ) ;
}
