static void
F_1 ( T_1 * V_1 )
{
T_2 V_2 ;
char * V_3 , * V_4 ;
V_2 = V_1 -> V_5 ;
if ( V_2 == 0 || V_1 -> V_1 [ V_2 - 1 ] != '\n' )
F_2 ( V_1 , L_1 ) ;
V_3 = V_1 -> V_1 ;
while ( * V_3 != '\0' ) {
V_4 = strchr ( V_3 , '\n' ) ;
if ( V_4 - V_3 > 80 ) {
V_4 = V_3 + 80 ;
while ( V_4 > V_3 && * V_4 != ' ' )
V_4 -- ;
if ( V_4 != V_3 )
* V_4 = '\n' ;
}
V_3 = V_4 + 1 ;
}
}
void
F_3 ( T_1 * V_1 , void (* F_4)( T_1 * ) ,
void (* F_5)( T_1 * ) )
{
if ( sizeof( V_1 ) == 4 )
F_2 ( V_1 , L_2 ) ;
else
F_2 ( V_1 , L_3 ) ;
if ( F_4 )
(* F_4)( V_1 ) ;
F_2 ( V_1 , L_4 ) ;
F_6 ( V_1 ,
#ifdef F_7
L_5 , F_7 , V_6 ,
V_7 ) ;
#else
L_6 ) ;
static char *
F_8 ( T_3 V_8 , T_4 V_9 )
{
T_4 V_10 ;
V_10 = ( T_4 ) F_9 ( ( V_11 ) V_8 ,
( const void * ) V_9 ) ;
if ( V_10 == NULL )
return NULL ;
if ( F_10 ( V_10 ) != F_11 () ) {
return NULL ;
}
return F_12 ( V_10 ) ;
}
static T_5
F_13 ( T_1 * V_1 )
{
static const T_6 V_12 [] =
L_7 ;
static const T_6 V_13 [] =
L_8 ;
T_7 V_14 ;
T_8 V_15 ;
V_11 V_16 ;
char * string ;
V_14 = F_14 ( NULL ,
V_12 , sizeof V_12 - 1 ,
false ) ;
if ( V_14 == NULL )
return FALSE ;
V_15 = F_15 ( NULL ,
V_14 ) ;
F_16 ( V_14 ) ;
if ( V_15 == NULL )
return FALSE ;
if ( ! F_17 ( V_15 ) ) {
F_16 ( V_15 ) ;
V_14 = F_14 ( NULL ,
V_13 , sizeof V_13 - 1 ,
false ) ;
if ( V_14 == NULL )
return FALSE ;
V_15 = F_15 ( NULL ,
V_14 ) ;
F_16 ( V_14 ) ;
if ( V_15 == NULL )
return FALSE ;
if ( ! F_17 ( V_15 ) ) {
F_16 ( V_15 ) ;
return FALSE ;
}
}
#ifdef F_18
V_16 = ( V_11 ) F_19 ( NULL ,
V_15 , 0 , V_17 ,
NULL , NULL ) ;
#else
V_16 = ( V_11 ) F_20 ( NULL ,
V_15 , 0 , V_17 ,
NULL , NULL ) ;
#endif
if ( V_16 == NULL ) {
F_16 ( V_15 ) ;
return FALSE ;
}
if ( F_10 ( V_16 ) != F_21 () ) {
F_16 ( V_16 ) ;
F_22 ( V_15 ) ;
F_16 ( V_15 ) ;
return FALSE ;
}
string = F_8 ( V_16 ,
F_23 ( L_9 ) ) ;
if ( string == NULL ) {
F_16 ( V_16 ) ;
F_22 ( V_15 ) ;
F_16 ( V_15 ) ;
return FALSE ;
}
F_6 ( V_1 , L_10 , string ) ;
F_24 ( string ) ;
string = F_8 ( V_16 ,
F_23 ( L_11 ) ) ;
if ( string == NULL ) {
F_16 ( V_16 ) ;
F_22 ( V_15 ) ;
F_16 ( V_15 ) ;
return FALSE ;
}
F_6 ( V_1 , L_12 , string ) ;
F_24 ( string ) ;
string = F_8 ( V_16 ,
F_23 ( L_13 ) ) ;
if ( string == NULL ) {
F_16 ( V_16 ) ;
F_22 ( V_15 ) ;
F_16 ( V_15 ) ;
return FALSE ;
}
F_6 ( V_1 , L_14 , string ) ;
F_24 ( string ) ;
F_16 ( V_16 ) ;
F_22 ( V_15 ) ;
F_16 ( V_15 ) ;
return TRUE ;
}
void F_25 ( T_1 * V_1 )
{
#if F_26 ( V_18 )
T_9 V_19 ;
T_10 V_20 ;
T_11 V_21 ;
#elif F_26 ( V_22 )
struct V_23 V_24 ;
#endif
#if F_26 ( V_18 )
memset ( & V_19 , '\0' , sizeof V_19 ) ;
V_19 . V_25 = sizeof V_19 ;
if ( ! F_27 ( ( V_26 * ) & V_19 ) ) {
F_2 ( V_1 , L_15 ) ;
return;
}
memset ( & V_20 , '\0' , sizeof V_20 ) ;
V_21 = ( T_11 ) F_28 ( F_29 ( F_30 ( L_16 ) ) , L_17 ) ;
if( V_21 )
V_21 ( & V_20 ) ;
else
F_31 ( & V_20 ) ;
switch ( V_19 . V_27 ) {
case V_28 :
F_6 ( V_1 , L_18 ) ;
break;
case V_29 :
switch ( V_19 . V_30 ) {
case 4 :
switch ( V_19 . V_31 ) {
case 0 :
F_6 ( V_1 , L_19 ) ;
break;
case 10 :
F_6 ( V_1 , L_20 ) ;
break;
case 90 :
F_6 ( V_1 , L_21 ) ;
break;
default:
F_6 ( V_1 , L_22 ,
V_19 . V_30 , V_19 . V_31 ) ;
break;
}
break;
default:
F_6 ( V_1 , L_22 ,
V_19 . V_30 , V_19 . V_31 ) ;
break;
}
break;
case V_32 :
switch ( V_19 . V_30 ) {
case 3 :
case 4 :
F_6 ( V_1 , L_23 ,
V_19 . V_30 , V_19 . V_31 ) ;
break;
case 5 :
switch ( V_19 . V_31 ) {
case 0 :
F_6 ( V_1 , L_24 ) ;
break;
case 1 :
F_6 ( V_1 , L_25 ) ;
break;
case 2 :
if ( ( V_19 . V_33 == V_34 ) &&
( V_20 . V_35 == V_36 ) ) {
F_6 ( V_1 , L_26 ) ;
} else {
F_6 ( V_1 , L_27 ) ;
if ( V_20 . V_35 == V_36 )
F_6 ( V_1 , L_28 ) ;
}
break;
default:
F_6 ( V_1 , L_29 ,
V_19 . V_30 , V_19 . V_31 ) ;
break;
}
break;
case 6 : {
T_5 V_37 ;
if ( V_20 . V_35 == V_36 )
F_2 ( V_1 , L_30 ) ;
else if ( V_20 . V_35 == V_38 )
F_2 ( V_1 , L_31 ) ;
#ifndef V_34
#define V_34 0x01
V_37 = ( ( V_19 . V_39 [ 1 ] & 0xff ) == V_34 ) ;
#else
V_37 = ( V_19 . V_33 == V_34 ) ;
#endif
switch ( V_19 . V_31 ) {
case 0 :
F_6 ( V_1 , V_37 ? L_32 : L_33 ) ;
break;
case 1 :
F_6 ( V_1 , V_37 ? L_34 : L_35 ) ;
break;
case 2 :
F_6 ( V_1 , V_37 ? L_36 : L_37 ) ;
break;
case 3 :
F_6 ( V_1 , V_37 ? L_38 : L_39 ) ;
break;
default:
F_6 ( V_1 , L_29 ,
V_19 . V_30 , V_19 . V_31 ) ;
break;
}
break;
}
default:
F_6 ( V_1 , L_29 ,
V_19 . V_30 , V_19 . V_31 ) ;
break;
}
break;
default:
F_6 ( V_1 , L_40 ,
V_19 . V_27 , V_19 . V_30 , V_19 . V_31 ) ;
break;
}
if ( V_19 . V_40 [ 0 ] != '\0' )
F_6 ( V_1 , L_12 , F_32 ( V_19 . V_40 ) ) ;
F_6 ( V_1 , L_41 , V_19 . V_41 ) ;
#elif F_26 ( V_22 )
if ( F_33 ( & V_24 ) < 0 ) {
F_6 ( V_1 , L_42 ,
F_34 ( V_42 ) ) ;
return;
}
if ( strcmp ( V_24 . V_43 , L_43 ) == 0 ) {
F_6 ( V_1 , L_44 , V_24 . V_43 , V_24 . V_44 ,
V_24 . V_45 ) ;
} else {
#ifdef F_35
if ( F_13 ( V_1 ) ) {
F_6 ( V_1 , L_45 , V_24 . V_43 , V_24 . V_45 ) ;
} else {
F_6 ( V_1 , L_46 , V_24 . V_43 , V_24 . V_45 ) ;
}
#else
F_6 ( V_1 , L_46 , V_24 . V_43 , V_24 . V_45 ) ;
#endif
}
#else
F_2 ( V_1 , L_47 ) ;
#endif
}
static void
F_36 ( int * V_46 , T_12 V_47 ) {
F_37 ( V_46 , V_47 ) ;
}
static inline void
F_36 ( T_12 * V_46 , int V_47 )
{
__asm__ __volatile__("cpuid"
: "=a" (CPUInfo[0]),
"=b" (CPUInfo[1]),
"=c" (CPUInfo[2]),
"=d" (CPUInfo[3])
: "a"(selector));
}
static void
F_36 ( T_12 * V_46 , int V_47 V_48 ) {
V_46 [ 0 ] = 0 ;
}
static void
F_36 ( T_12 * V_46 , int V_47 V_48 ) {
V_46 [ 0 ] = 0 ;
}
static void F_38 ( T_1 * V_1 V_48 )
{
#if F_26 ( V_49 )
int V_46 [ 4 ] ;
#else
T_12 V_46 [ 4 ] ;
#endif
char V_50 [ 0x40 ] ;
unsigned V_51 ;
F_36 ( V_46 , 0x80000000 ) ;
V_51 = V_46 [ 0 ] ;
if( V_51 < 0x80000005 )
return;
memset ( V_50 , 0 , sizeof( V_50 ) ) ;
F_36 ( V_46 , 0x80000002 ) ;
memcpy ( V_50 , V_46 , sizeof( V_46 ) ) ;
F_36 ( V_46 , 0x80000003 ) ;
memcpy ( V_50 + 16 , V_46 , sizeof( V_46 ) ) ;
F_36 ( V_46 , 0x80000004 ) ;
memcpy ( V_50 + 32 , V_46 , sizeof( V_46 ) ) ;
F_6 ( V_1 , L_48 , V_50 ) ;
}
static void F_39 ( T_1 * V_1 V_48 )
{
#if F_26 ( V_18 )
T_13 V_52 ;
V_52 . V_53 = sizeof ( V_52 ) ;
if( F_40 ( & V_52 ) )
F_6 (str, L_49%L_50dL_51MB of physical memory.\nL_52on L_53LANGL_54 , with locale %sL_55 , without localeL_56 , L_57 , with libz %sL_58.L_59\n\nBuilt using clang %s.\nL_60\n\nBuilt using llvm-gcc %s.\nL_61\n\nBuilt using gcc %s.\nL_62\n\nBuilt using HP aCC %d.\nL_63\n\nBuilt using IBM XL C %d.%d\nL_64 patch %dL_65\nL_66\n\nBuilt using Intel C %d.%dL_67 patch %dL_68 , compiler built %04d-%02d-%02d L_69\nL_70\n\nBuilt using Microsoft Visual C++ %d.%dL_71 build %dL_72\n\nBuilt using Microsoft Visual C++ %d.%dL_73 build %dL_74\nL_75\n\nBuilt using Microsoft Visual C++ %d.%d\nL_76\n\nBuilt using Sun C %d.%dL_77 patch %dL_78\nL_79Copyright 1998-2014 Gerald Combs <gerald@wireshark.org> and contributors.\nL_80This is free software; see the source for copying conditions. There is NO\nL_80warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n"
