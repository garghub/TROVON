void F_1 ( T_1 * V_1 , int V_2 )
{
const struct V_3 * V_4 = V_1 -> V_5 -> V_4 ;
if ( V_4 && V_4 -> V_6 )
V_4 -> V_6 ( V_1 , V_2 ) ;
}
T_2 F_2 ( T_1 * V_1 )
{
struct V_7 V_8 ;
V_1 -> V_5 -> V_9 -> V_10 ( V_1 , & V_8 , V_11 ) ;
return V_8 . error ;
}
void F_3 ( T_3 * V_12 )
{
#ifndef F_4
# ifdef F_5
int V_13 ;
for ( V_13 = 0 ; V_13 < 256 ; V_13 ++ )
V_12 [ V_13 ] = F_6 ( V_12 [ V_13 ] ) ;
# else
# error "Please fix <asm/byteorder.h>"
# endif
#endif
}
void F_7 ( T_2 * V_14 , const int V_15 , const int V_16 )
{
T_2 * V_17 , * V_18 = & V_14 [ V_15 & ~ 1 ] ;
if ( V_16 ) {
for ( V_17 = V_14 ; V_17 != V_18 ; V_17 += 2 )
F_8 ( ( T_3 * ) V_17 ) ;
}
V_17 = V_14 ;
while ( V_14 != V_18 && * V_14 == ' ' )
++ V_14 ;
while ( V_14 != V_18 && * V_14 ) {
if ( * V_14 ++ != ' ' || ( V_14 != V_18 && * V_14 && * V_14 != ' ' ) )
* V_17 ++ = * ( V_14 - 1 ) ;
}
while ( V_17 != V_18 )
* V_17 ++ = '\0' ;
}
int F_9 ( T_1 * V_1 , T_2 V_19 , T_2 V_20 ,
unsigned long V_21 , T_2 * V_22 )
{
T_4 * V_5 = V_1 -> V_5 ;
const struct V_23 * V_9 = V_5 -> V_9 ;
unsigned long V_24 ;
int V_13 ;
T_2 V_25 ;
F_10 ( 1 ) ;
V_25 = V_9 -> V_26 ( V_5 ) ;
if ( V_25 & V_27 ) {
F_11 ( V_24 ) ;
F_12 () ;
V_21 += V_28 ;
while ( ( V_25 = V_9 -> V_26 ( V_5 ) ) & V_27 ) {
if ( F_13 ( V_28 , V_21 ) ) {
V_25 = V_9 -> V_26 ( V_5 ) ;
if ( ( V_25 & V_27 ) == 0 )
break;
F_14 ( V_24 ) ;
* V_22 = V_25 ;
return - V_29 ;
}
}
F_14 ( V_24 ) ;
}
for ( V_13 = 0 ; V_13 < 10 ; V_13 ++ ) {
F_10 ( 1 ) ;
V_25 = V_9 -> V_26 ( V_5 ) ;
if ( F_15 ( V_25 , V_19 , V_20 ) ) {
* V_22 = V_25 ;
return 0 ;
}
}
* V_22 = V_25 ;
return - V_30 ;
}
int F_16 ( T_5 * V_31 , T_1 * V_1 , T_2 V_19 ,
T_2 V_20 , unsigned long V_21 )
{
int V_32 ;
T_2 V_25 ;
if ( V_1 -> V_33 && ( V_1 -> V_34 > V_1 -> V_33 ) ) {
* V_31 = V_35 ;
return 1 ;
}
V_32 = F_9 ( V_1 , V_19 , V_20 , V_21 , & V_25 ) ;
if ( V_32 ) {
char * V_14 = ( V_32 == - V_29 ) ? L_1 : L_2 ;
* V_31 = F_17 ( V_1 , V_14 , V_25 ) ;
}
return V_32 ;
}
int F_18 ( T_3 * V_12 , const struct V_36 * V_37 )
{
for ( ; V_37 -> V_38 ; V_37 ++ )
if ( ( ! strcmp ( V_37 -> V_38 , ( char * ) & V_12 [ V_39 ] ) ) &&
( ! V_37 -> V_40 ||
strstr ( ( char * ) & V_12 [ V_41 ] , V_37 -> V_40 ) ) )
return 1 ;
return 0 ;
}
T_2 F_19 ( T_1 * V_1 )
{
T_4 * V_5 = V_1 -> V_5 ;
T_3 * V_12 = V_1 -> V_12 ;
int V_42 = F_18 ( V_12 , V_43 ) ;
if ( V_5 -> V_44 == V_45 || V_5 -> V_44 == V_46 )
return 1 ;
if ( V_42 )
F_20 ( V_47 L_3 ,
V_1 -> V_48 ) ;
if ( F_21 ( V_12 ) && ! V_42 )
return 1 ;
if ( V_5 -> V_44 != V_49 && ! V_42 )
goto V_50;
if ( V_12 [ V_51 ] & 0x4000 )
return 1 ;
if ( V_42 ) {
const char * V_52 = ( char * ) & V_12 [ V_39 ] ;
if ( strstr ( V_52 , L_4 ) ) {
if ( V_5 -> V_44 == V_49 )
return 1 ;
} else {
if ( V_12 [ V_51 ] & 0x2000 )
return 1 ;
}
}
V_50:
if ( V_1 -> V_53 & V_54 )
return 0 ;
F_20 ( V_55 L_5
L_6 ,
V_1 -> V_48 ,
V_5 -> V_44 == V_49 ? L_7 : L_8 ) ;
V_1 -> V_53 |= V_54 ;
return 0 ;
}
void F_22 ( T_1 * V_1 )
{
const char * * V_56 , * V_57 = ( char * ) & V_1 -> V_12 [ V_39 ] ;
for ( V_56 = V_58 ; * V_56 != NULL ; V_56 ++ )
if ( strstr ( V_57 , * V_56 ) != NULL ) {
V_1 -> V_53 |= V_59 ;
return;
}
}
int F_23 ( T_1 * V_1 )
{
T_3 * V_12 ;
int V_60 ;
V_12 = F_24 ( V_61 , V_62 ) ;
if ( V_12 == NULL )
return 0 ;
F_1 ( V_1 , 1 ) ;
V_60 = F_25 ( V_1 , V_63 , V_12 , 1 ) ;
F_1 ( V_1 , 0 ) ;
if ( V_60 )
goto V_64;
V_1 -> V_12 [ V_65 ] = V_12 [ V_65 ] ;
V_1 -> V_12 [ V_66 ] = V_12 [ V_66 ] ;
V_1 -> V_12 [ V_67 ] = V_12 [ V_67 ] ;
V_1 -> V_12 [ V_68 ] = V_12 [ V_68 ] ;
F_26 ( V_12 ) ;
return 1 ;
V_64:
if ( V_60 == 2 )
F_20 ( V_69 L_9 , V_1 -> V_48 , V_70 ) ;
F_26 ( V_12 ) ;
return 0 ;
}
int F_27 ( T_1 * V_1 , T_2 V_71 )
{
T_4 * V_5 = V_1 -> V_5 ;
const struct V_23 * V_9 = V_5 -> V_9 ;
struct V_7 V_8 ;
T_3 * V_12 = V_1 -> V_12 , V_13 ;
int error = 0 ;
T_2 V_25 ;
#ifdef F_28
if ( V_5 -> V_72 )
V_5 -> V_72 -> V_73 ( V_1 , 0 ) ;
#endif
if ( ( V_71 & 0xf8 ) == V_74 && F_29 ( V_1 -> V_12 ) == 0 )
goto V_75;
F_10 ( 1 ) ;
V_9 -> V_76 ( V_1 ) ;
F_1 ( V_1 , 1 ) ;
F_10 ( 1 ) ;
V_9 -> V_77 ( V_5 , V_78 | V_79 ) ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_80 = V_81 ;
V_8 . V_82 = V_71 ;
V_9 -> V_83 ( V_1 , & V_8 , V_84 | V_85 ) ;
V_9 -> V_86 ( V_5 , V_87 ) ;
if ( V_1 -> V_53 & V_59 )
V_9 -> V_77 ( V_5 , V_79 ) ;
error = F_9 ( V_1 , V_1 -> V_88 ,
V_27 | V_89 | V_90 ,
V_91 , & V_25 ) ;
F_1 ( V_1 , 0 ) ;
if ( error ) {
( void ) F_30 ( V_1 , L_10 , V_25 ) ;
return error ;
}
if ( V_71 >= V_92 ) {
V_12 [ V_65 ] &= ~ 0xFF00 ;
V_12 [ V_66 ] &= ~ 0x0700 ;
V_12 [ V_67 ] &= ~ 0x0700 ;
if ( F_31 ( V_12 ) )
V_12 [ V_68 ] &= ~ 0x0E00 ;
} else if ( F_31 ( V_12 ) )
V_12 [ V_68 ] &= ~ 0x01C0 ;
V_75:
#ifdef F_28
if ( V_71 >= V_92 && ( V_1 -> V_53 & V_93 ) )
V_5 -> V_72 -> V_73 ( V_1 , 1 ) ;
else if ( V_5 -> V_72 )
F_32 ( V_1 ) ;
#endif
if ( V_71 >= V_94 ) {
V_13 = 1 << ( V_71 - V_94 ) ;
V_12 [ V_65 ] |= ( V_13 << 8 | V_13 ) ;
} else if ( F_31 ( V_12 ) && V_71 >= V_95 ) {
V_13 = V_71 - V_96 ;
V_12 [ V_68 ] |= V_13 << 9 ;
} else if ( V_71 >= V_97 ) {
V_13 = 1 << ( V_71 - V_97 ) ;
V_12 [ V_66 ] |= ( V_13 << 8 | V_13 ) ;
} else if ( V_71 >= V_92 ) {
V_13 = 1 << ( V_71 - V_92 ) ;
V_12 [ V_67 ] |= ( V_13 << 8 | V_13 ) ;
} else if ( F_31 ( V_12 ) && V_71 >= V_98 ) {
V_13 = V_71 - V_99 ;
V_12 [ V_68 ] |= V_13 << 6 ;
}
if ( ! V_1 -> V_100 )
V_1 -> V_100 = V_71 ;
V_1 -> V_101 = V_71 ;
return error ;
}
void F_33 ( T_1 * V_1 , T_6 * V_102 ,
unsigned int V_21 )
{
T_4 * V_5 = V_1 -> V_5 ;
F_34 ( V_5 -> V_102 ) ;
V_5 -> V_102 = V_102 ;
V_5 -> V_103 . V_104 = V_28 + V_21 ;
V_5 -> V_105 = V_5 -> V_106 ;
F_35 ( & V_5 -> V_103 ) ;
}
void F_36 ( T_1 * V_1 , T_6 * V_102 ,
unsigned int V_21 )
{
T_4 * V_5 = V_1 -> V_5 ;
unsigned long V_24 ;
F_37 ( & V_5 -> V_107 , V_24 ) ;
F_33 ( V_1 , V_102 , V_21 ) ;
F_38 ( & V_5 -> V_107 , V_24 ) ;
}
void F_39 ( T_1 * V_1 , struct V_108 * V_109 ,
T_6 * V_102 , unsigned V_21 )
{
T_4 * V_5 = V_1 -> V_5 ;
unsigned long V_24 ;
F_37 ( & V_5 -> V_107 , V_24 ) ;
if ( ( V_109 -> V_110 != V_111 &&
V_109 -> V_110 != V_112 ) ||
( V_1 -> V_113 & V_114 ) )
F_33 ( V_1 , V_102 , V_21 ) ;
V_5 -> V_9 -> V_86 ( V_5 , V_109 -> V_8 . V_115 ) ;
F_40 ( 400 ) ;
F_38 ( & V_5 -> V_107 , V_24 ) ;
}
int F_41 ( T_4 * V_5 , unsigned long V_21 )
{
T_2 V_25 = 0 ;
while ( V_21 -- ) {
F_42 ( 1 ) ;
V_25 = V_5 -> V_9 -> V_26 ( V_5 ) ;
if ( ( V_25 & V_27 ) == 0 )
return 0 ;
if ( V_25 == 0xff )
return - V_116 ;
F_43 () ;
F_44 () ;
}
return - V_29 ;
}
