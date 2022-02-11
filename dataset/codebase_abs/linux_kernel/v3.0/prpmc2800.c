static struct V_1 * F_1 ( T_1 * V_2 )
{
struct V_1 * V_3 ;
int V_4 ;
for ( V_4 = 0 , V_3 = V_1 ; V_4 < F_2 ( V_1 ) ;
V_4 ++ , V_3 ++ )
if ( ( V_2 [ 0 ] == V_3 -> V_5 ) && ( V_2 [ 1 ] == V_3 -> V_6 )
&& ( ( V_2 [ 4 ] & V_3 -> V_7 ) == V_3 -> V_8 ) )
return V_3 ;
return NULL ;
}
static struct V_1 * F_3 ( void )
{
struct V_1 * V_3 ;
T_1 V_2 [ 5 ] ;
int V_9 ;
if ( F_4 () )
F_5 ( L_1 ) ;
memset ( V_2 , 0 , sizeof( V_2 ) ) ;
V_9 = F_6 ( V_10 , V_2 , 0x1fde , 2 , sizeof( V_2 ) ) ;
if ( V_9 < 0 )
F_5 ( L_2 ) ;
F_7 () ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 == NULL ) {
printf ( L_3 ) ;
printf ( L_4 ,
V_2 [ 0 ] , V_2 [ 1 ] , V_2 [ 2 ] , V_2 [ 3 ] , V_2 [ 4 ] ) ;
printf ( L_5 ) ;
}
return V_3 ;
}
static void F_8 ( T_2 V_11 )
{
T_2 V_4 , V_12 [ 12 ] , V_13 , V_14 ;
T_2 V_15 , V_16 , V_17 , V_18 [ 2 ] ;
unsigned long V_19 ;
int V_9 ;
void * V_20 ;
T_1 * V_21 , V_22 ;
struct V_23 * V_24 ;
V_21 = F_9 () ;
V_22 = F_10 () ;
if ( V_22 )
V_14 = V_25
| V_26
| V_27
| V_28 ;
else
V_14 = V_29
| V_26
| V_30
| V_31 ;
F_11 ( V_32 , V_21 , V_22 ) ;
F_12 ( V_32 , V_21 , 0 , 0 , V_11 ,
V_14 ) ;
V_20 = F_13 ( NULL , L_6 ) ;
if ( V_20 == NULL )
F_5 ( L_7
L_8 ) ;
V_9 = F_14 ( V_20 , L_9 , V_12 , sizeof( V_12 ) ) ;
if ( V_9 != sizeof( V_12 ) )
F_5 ( L_10
L_11 ) ;
V_20 = F_13 ( NULL , L_12 ) ;
if ( V_20 == NULL )
F_5 ( L_13 ) ;
V_13 = F_15 ( ( T_2 * ) ( V_32 + V_33 ) ) ;
V_13 |= 0x0007fe00 ;
F_16 ( ( T_2 * ) ( V_32 + V_33 ) , V_13 ) ;
for ( V_4 = 0 ; V_4 < 12 ; V_4 += 6 ) {
switch ( V_12 [ V_4 ] & 0xff000000 ) {
case 0x01000000 :
V_24 = V_34 ;
break;
case 0x02000000 :
V_24 = V_35 ;
break;
default:
continue;
}
V_15 = V_12 [ V_4 + 1 ] ;
V_16 = V_12 [ V_4 + 2 ] ;
V_19 = V_12 [ V_4 + 3 ] ;
V_17 = V_12 [ V_4 + 5 ] ;
V_18 [ 0 ] = V_19 ;
V_18 [ 1 ] = V_17 ;
if ( ! F_17 ( V_20 , V_18 , sizeof( V_18 ) , & V_19 ) )
F_5 ( L_14 ,
( T_2 ) V_19 ) ;
F_18 ( V_32 , 0 , V_15 ,
V_16 , V_19 , V_17 , V_24 ) ;
}
V_13 &= ~ 0x00000600 ;
F_16 ( ( T_2 * ) ( V_32 + V_33 ) , V_13 ) ;
}
static void F_19 ( void )
{
T_2 V_12 [ 2 ] , V_36 , V_11 ;
int V_9 ;
void * V_20 ;
char V_37 [ V_38 ] ;
struct V_1 * V_3 ;
V_3 = F_3 () ;
V_11 = ( V_3 ) ? V_3 -> V_11 : F_20 ( V_32 ) ;
F_8 ( V_11 ) ;
if ( ! V_3 )
return;
V_20 = F_21 ( L_15 ) ;
if ( V_20 == NULL )
F_5 ( L_16 ) ;
memset ( V_37 , 0 , V_38 ) ;
strncpy ( V_37 , V_39 , V_38 - 2 ) ;
V_36 = strlen ( V_37 ) ;
if ( V_3 -> V_37 == V_40 )
V_36 -- ;
V_37 [ V_36 ++ ] = V_3 -> V_41 ;
V_37 [ V_36 ++ ] = '\0' ;
F_22 ( V_20 , L_17 , V_37 , V_36 ) ;
V_20 = F_23 ( NULL , L_18 , L_19 ) ;
if ( V_20 == NULL )
F_5 ( L_20 ) ;
V_12 [ 0 ] = V_3 -> V_42 ;
F_22 ( V_20 , L_21 , & V_12 [ 0 ] , sizeof( V_12 [ 0 ] ) ) ;
V_20 = F_21 ( L_22 ) ;
if ( V_20 == NULL )
F_5 ( L_23 ) ;
V_12 [ 0 ] = 0 ;
V_12 [ 1 ] = V_3 -> V_11 ;
F_22 ( V_20 , L_24 , V_12 , sizeof( V_12 ) ) ;
if ( V_3 -> V_43 == V_44 ) {
V_20 = F_13 ( NULL , L_12 ) ;
if ( V_20 == NULL )
F_5 ( L_25
L_8 ) ;
F_22 ( V_20 , L_17 , L_26 , strlen ( L_26 ) + 1 ) ;
}
V_20 = F_13 ( NULL , L_27 ) ;
if ( V_20 == NULL )
F_5 ( L_28 ) ;
V_9 = F_14 ( V_20 , L_24 , V_12 , sizeof( V_12 ) ) ;
if ( V_9 != sizeof( V_12 ) )
F_5 ( L_29 ) ;
V_12 [ 1 ] = V_3 -> V_45 ;
F_22 ( V_20 , L_24 , V_12 , sizeof( V_12 ) ) ;
}
static void F_24 ( void )
{
T_2 V_46 ;
F_25 ( 5000000 ) ;
if ( V_32 != 0 ) {
V_46 = F_15 ( ( T_2 * ) ( V_32 + V_47 ) ) ;
V_46 &= 0xFFFF0FFF ;
F_16 ( ( T_2 * ) ( V_32 + V_47 ) , V_46 ) ;
V_46 = F_15 ( ( T_2 * ) ( V_32 + V_48 ) ) ;
V_46 |= 0x00000004 ;
F_16 ( ( T_2 * ) ( V_32 + V_48 ) , V_46 ) ;
V_46 = F_15 ( ( T_2 * ) ( V_32 + V_49 ) ) ;
V_46 |= 0x00000004 ;
F_16 ( ( T_2 * ) ( V_32 + V_49 ) , V_46 ) ;
V_46 = F_15 ( ( T_2 * ) ( V_32 + V_50 ) ) ;
V_46 &= 0xFFFF0FFF ;
F_16 ( ( T_2 * ) ( V_32 + V_50 ) , V_46 ) ;
V_46 = F_15 ( ( T_2 * ) ( V_32 + V_48 ) ) ;
V_46 |= 0x00080000 ;
F_16 ( ( T_2 * ) ( V_32 + V_48 ) , V_46 ) ;
V_46 = F_15 ( ( T_2 * ) ( V_32 + V_49 ) ) ;
V_46 |= 0x00080000 ;
F_16 ( ( T_2 * ) ( V_32 + V_49 ) , V_46 ) ;
F_16 ( ( T_2 * ) ( V_32 + V_51 ) ,
0x00080004 ) ;
}
for (; ; ) ;
}
void F_26 ( unsigned long V_52 , unsigned long V_53 , unsigned long V_54 ,
unsigned long V_55 , unsigned long V_56 )
{
struct V_57 V_58 ;
char * V_59 , * V_60 ;
int V_61 = V_62 - V_63 ;
void * V_64 = V_65 ;
unsigned long V_66 = V_67 - V_65 ;
char V_68 [ 256 ] ;
if ( V_61 <= 0 )
exit () ;
F_27 ( & V_69 , V_64 , V_66 ) ;
F_28 ( & V_69 , V_68 , sizeof( V_68 ) ) ;
if ( ! F_29 ( V_68 , & V_58 ) )
exit () ;
V_59 = ( char * ) ( V_58 . V_70 + V_58 . V_71 ) ;
V_59 = F_30 ( V_59 , ( char * ) V_72 ) ;
if ( ( unsigned ) F_31 ( V_59 , V_73 , 2 * V_74 , 16 )
> ( 128 * V_75 ) )
exit () ;
V_60 = malloc ( V_61 ) ;
if ( ! V_60 )
exit () ;
memmove ( V_60 , V_63 , V_61 ) ;
F_32 ( V_60 ) ;
V_32 = F_33 () ;
V_76 . V_77 = F_19 ;
V_76 . exit = F_24 ;
if ( F_34 () < 0 )
exit () ;
}
