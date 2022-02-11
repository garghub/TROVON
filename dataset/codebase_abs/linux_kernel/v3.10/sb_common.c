int F_1 ( T_1 * V_1 , unsigned char V_2 )
{
int V_3 ;
unsigned long V_4 ;
V_4 = V_5 + V_6 / 10 ;
for ( V_3 = 0 ; V_3 < 500000 && ( V_4 - V_5 ) > 0 ; V_3 ++ )
{
if ( ( F_2 ( V_7 ) & 0x80 ) == 0 )
{
F_3 ( ( V_2 ) , V_8 ) ;
return 1 ;
}
}
F_4 ( V_9 L_1 , V_2 ) ;
return 0 ;
}
int F_5 ( T_1 * V_1 )
{
int V_3 ;
for ( V_3 = 1000 ; V_3 ; V_3 -- )
{
if ( F_2 ( V_10 ) & 0x80 )
return F_2 ( V_11 ) ;
}
return 0xffff ;
}
static void F_6 ( T_1 * V_1 )
{
int V_12 ;
unsigned char V_13 = 0xff ;
if ( V_1 -> V_14 == V_15 )
{
V_13 = F_7 ( V_1 , V_16 ) ;
if ( V_13 & 4 )
if( V_1 -> V_17 )
F_8 ( V_1 -> V_18 , V_1 -> V_17 ) ;
if ( ! ( V_13 & 3 ) )
return;
}
if ( V_1 -> V_19 && ( ! V_1 -> V_20 || ( V_13 & 0x01 ) ) )
{
switch ( V_1 -> V_21 )
{
case V_22 :
F_9 ( V_1 -> V_23 , 1 ) ;
break;
case V_24 :
F_10 ( V_1 -> V_23 ) ;
break;
case V_25 :
break;
case V_26 :
F_11 ( V_1 ) ;
break;
default:
;
}
}
else if ( V_1 -> V_27 && ( V_13 & 0x02 ) )
{
switch ( V_1 -> V_28 )
{
case V_22 :
F_9 ( V_1 -> V_23 , 1 ) ;
break;
case V_24 :
F_10 ( V_1 -> V_23 ) ;
break;
case V_25 :
break;
default:
;
}
}
if ( V_13 & 0x01 )
V_12 = F_2 ( V_10 ) ;
if ( V_1 -> V_14 == V_15 && V_13 & 0x02 )
V_12 = F_2 ( V_29 ) ;
}
static void F_12 ( T_1 * V_1 )
{
int V_13 = F_2 ( V_1 -> V_30 + 0x1A ) ;
V_13 &= 3 ;
if( V_13 )
F_6 ( V_1 ) ;
}
static T_2 F_13 ( int V_18 , void * V_31 )
{
T_1 * V_1 = V_31 ;
V_1 -> V_32 = 1 ;
switch ( V_1 -> V_14 ) {
case V_33 :
F_12 ( V_1 ) ;
break;
case V_34 :
F_14 ( V_1 ) ;
break;
default:
F_6 ( V_1 ) ;
break;
}
return V_35 ;
}
int F_15 ( T_1 * V_1 )
{
int V_36 ;
F_16 ( F_4 ( L_2 ) ) ;
if ( V_1 -> V_14 == V_34 ) return F_17 ( V_1 ) ;
F_3 ( 1 , V_37 ) ;
F_18 ( 10 ) ;
F_3 ( 0 , V_37 ) ;
F_18 ( 30 ) ;
for ( V_36 = 0 ; V_36 < 1000 && ! ( F_2 ( V_10 ) & 0x80 ) ; V_36 ++ ) ;
if ( F_2 ( V_11 ) != 0xAA )
{
F_19 ( F_4 ( L_3 ) ) ;
return 0 ;
}
F_16 ( F_4 ( L_4 ) ) ;
return 1 ;
}
static void F_20 ( T_1 * V_1 )
{
int V_3 ;
unsigned long V_38 ;
F_19 ( F_4 ( L_5 ) ) ;
F_21 ( & V_1 -> V_39 , V_38 ) ;
V_1 -> V_40 = V_1 -> V_41 = 0 ;
F_1 ( V_1 , 0xe1 ) ;
for ( V_3 = 100000 ; V_3 ; V_3 -- )
{
if ( F_2 ( V_10 ) & 0x80 )
{
if ( V_1 -> V_40 == 0 )
V_1 -> V_40 = F_2 ( V_11 ) ;
else
{
V_1 -> V_41 = F_2 ( V_11 ) ;
break;
}
}
}
F_22 ( & V_1 -> V_39 , V_38 ) ;
F_19 ( F_4 ( L_6 , V_1 -> V_40 , V_1 -> V_41 ) ) ;
}
static int F_23 ( T_1 * V_1 )
{
int V_42 ;
if ( V_1 -> V_43 != 0 && V_1 -> V_43 != 1 && V_1 -> V_43 != 3 )
{
F_4 ( V_44 L_7 , V_1 -> V_43 ) ;
return 0 ;
}
V_42 = ( 1 << V_1 -> V_43 ) ;
if ( V_1 -> V_45 >= 5 && V_1 -> V_45 <= 7 )
V_42 |= ( 1 << V_1 -> V_45 ) ;
F_24 ( V_1 , V_46 , V_42 ) ;
return 1 ;
}
static void F_25 ( T_1 * V_1 , struct V_47 * V_48 )
{
unsigned char V_42 = F_7 ( V_1 , 0x84 ) & ~ 0x06 ;
switch ( V_48 -> V_49 )
{
case 0x300 :
F_24 ( V_1 , 0x84 , V_42 | 0x04 ) ;
break;
case 0x330 :
F_24 ( V_1 , 0x84 , V_42 | 0x00 ) ;
break;
default:
F_24 ( V_1 , 0x84 , V_42 | 0x02 ) ;
F_4 ( V_44 L_8 , V_48 -> V_49 ) ;
}
}
static int F_26 ( T_1 * V_1 , int V_50 )
{
int V_51 ;
switch ( V_50 )
{
case 5 :
V_51 = 2 ;
break;
case 7 :
V_51 = 4 ;
break;
case 9 :
V_51 = 1 ;
break;
case 10 :
V_51 = 8 ;
break;
default:
F_4 ( V_44 L_9 , V_50 ) ;
return 0 ;
}
F_24 ( V_1 , V_52 , V_51 ) ;
return 1 ;
}
static void F_27 ( T_1 * V_1 , struct V_47 * V_48 )
{
unsigned char V_42 = 0 ;
unsigned long V_38 ;
if ( V_53 != 0 && V_53 != V_48 -> V_49 )
return;
switch ( V_48 -> V_49 )
{
case 0x220 :
V_42 = 1 ;
break;
case 0x240 :
V_42 = 2 ;
break;
case 0x260 :
V_42 = 3 ;
break;
default:
return;
}
V_42 = V_54 = V_42 << 5 ;
V_53 = V_48 -> V_49 ;
F_21 ( & V_55 , V_38 ) ;
F_3 ( ( 0xAF ) , 0x201 ) ;
F_3 ( ( 0x50 ) , 0x201 ) ;
F_3 ( ( V_42 ) , 0x201 ) ;
F_22 ( & V_55 , V_38 ) ;
}
static int F_28 ( T_1 * V_1 , struct V_47 * V_48 )
{
char V_56 [ 100 ] ;
if ( ! F_1 ( V_1 , 0xfa ) )
return 0 ;
if ( F_5 ( V_1 ) != 0x12 )
return 0 ;
if ( V_48 -> V_18 < 1 || V_48 -> V_18 > 15 || V_57 [ V_48 -> V_18 ] == 0 )
{
F_4 ( V_44 L_10 , V_48 -> V_18 ) ;
return 0 ;
}
if ( V_48 -> V_58 < 0 || V_48 -> V_58 > 3 || V_59 [ V_48 -> V_58 ] == 0 )
{
F_4 ( V_44 L_11 , V_48 -> V_58 ) ;
return 0 ;
}
if ( V_48 -> V_60 < 0 )
{
F_4 ( V_44 L_12 ) ;
return 0 ;
}
if ( V_48 -> V_60 < 5 || V_48 -> V_60 > 7 || V_59 [ V_48 -> V_60 ] == 0 )
{
F_4 ( V_44 L_13 , V_48 -> V_60 ) ;
return 0 ;
}
V_1 -> V_45 = V_48 -> V_60 ;
if ( ! F_1 ( V_1 , 0xfb ) )
return 0 ;
if ( ! F_1 ( V_1 , V_59 [ V_48 -> V_58 ] |
( V_59 [ V_48 -> V_60 ] << 4 ) ) )
return 0 ;
if ( ! F_1 ( V_1 , V_57 [ V_48 -> V_18 ] ) )
return 0 ;
V_1 -> V_14 = V_61 ;
strcpy ( V_56 , L_14 ) ;
V_48 -> V_56 = L_14 ;
V_1 -> V_62 |= V_63 ;
return 1 ;
}
static void F_29 ( T_1 * V_1 )
{
unsigned char V_42 ;
switch ( V_1 -> V_64 )
{
case 0x220 :
V_42 = 0x04 ;
break;
case 0x230 :
V_42 = 0x05 ;
break;
case 0x240 :
V_42 = 0x06 ;
break;
case 0x250 :
V_42 = 0x07 ;
break;
default:
return;
}
F_19 ( F_4 ( L_15 ) ) ;
F_2 ( 0x229 ) ;
F_2 ( 0x229 ) ;
F_2 ( 0x229 ) ;
F_2 ( 0x22b ) ;
F_2 ( 0x229 ) ;
F_2 ( 0x22b ) ;
F_2 ( 0x229 ) ;
F_2 ( 0x229 ) ;
F_2 ( 0x22b ) ;
F_2 ( 0x229 ) ;
F_2 ( V_1 -> V_64 ) ;
if ( F_15 ( V_1 ) )
return;
#if 0
outb((0x00), 0xfb);
outb((0x00), 0xe0);
outb((bits), 0xe1);
outb((0x00), 0xf9);
#endif
}
int F_30 ( struct V_47 * V_48 , int V_65 , int V_66 , struct V_67 * V_68 )
{
T_1 V_69 ;
T_1 * V_1 = & V_69 ;
memset ( ( char * ) & V_69 , 0 , sizeof( V_69 ) ) ;
if( V_68 ) memcpy ( & V_1 -> V_68 , V_68 , sizeof( struct V_67 ) ) ;
V_69 . V_70 = - 1 ;
V_69 . V_71 = - 1 ;
V_69 . V_23 = - 1 ;
F_19 ( F_4 ( L_16 , V_48 -> V_49 ) ) ;
F_31 ( & V_1 -> V_39 ) ;
V_1 -> type = V_48 -> V_72 ;
V_1 -> V_64 = V_48 -> V_49 ;
V_1 -> V_18 = V_48 -> V_18 ;
V_1 -> V_43 = V_48 -> V_58 ;
V_1 -> V_45 = - 1 ;
V_1 -> V_30 = V_66 ;
if( V_65 == V_73 )
{
V_1 -> V_14 = V_33 ;
V_1 -> V_62 |= V_74 ;
V_48 -> V_75 |= V_74 ;
V_48 -> V_72 = V_33 ;
}
if( V_65 == V_76 )
{
V_1 -> V_14 = V_77 ;
V_1 -> V_62 |= V_74 ;
V_48 -> V_75 |= V_74 ;
V_48 -> V_72 = V_77 ;
F_4 ( L_17 ) ;
}
if ( V_1 -> V_68 . V_78 )
{
unsigned long V_38 ;
F_21 ( & V_1 -> V_39 , V_38 ) ;
F_2 ( V_1 -> V_64 + 0x09 ) ;
F_2 ( V_1 -> V_64 + 0x09 ) ;
F_2 ( V_1 -> V_64 + 0x09 ) ;
F_2 ( V_1 -> V_64 + 0x0b ) ;
F_2 ( V_1 -> V_64 + 0x09 ) ;
F_2 ( V_1 -> V_64 + 0x0b ) ;
F_2 ( V_1 -> V_64 + 0x09 ) ;
F_2 ( V_1 -> V_64 + 0x09 ) ;
F_2 ( V_1 -> V_64 + 0x0b ) ;
F_2 ( V_1 -> V_64 + 0x09 ) ;
F_2 ( V_1 -> V_64 + 0x00 ) ;
F_22 ( & V_1 -> V_39 , V_38 ) ;
}
if ( F_15 ( V_1 ) )
F_20 ( V_1 ) ;
else
V_1 -> V_40 = 0 ;
if ( V_1 -> type == 0 || V_1 -> type == V_61 || V_1 -> type == V_79 )
if ( V_1 -> V_40 == 0 || ( V_1 -> V_40 == 3 && V_1 -> V_41 == 1 ) )
F_27 ( V_1 , V_48 ) ;
if ( V_1 -> V_40 == 0 && ( V_1 -> type == V_34 || V_1 -> type == 0 ) )
F_29 ( V_1 ) ;
if ( ! F_15 ( V_1 ) )
{
F_19 ( F_4 ( L_18 ) ) ;
#ifdef F_32
F_4 ( V_80 L_19 ) ;
#endif
return 0 ;
}
if ( V_1 -> V_40 == 0 )
F_20 ( V_1 ) ;
if ( V_1 -> V_40 == 3 && V_1 -> V_41 == 1 )
{
if ( V_1 -> type == V_81 )
{
if ( F_1 ( V_1 , 0x09 ) )
if ( F_1 ( V_1 , 0x00 ) )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < 10000 ; V_3 ++ )
F_2 ( V_10 ) ;
V_1 -> V_62 = V_82 | V_63 ;
V_1 -> V_14 = V_81 ;
}
}
}
if( V_1 -> type == V_33 )
V_1 -> V_14 = V_33 ;
if( V_1 -> type == V_77 )
{
F_4 ( L_20 ) ;
V_1 -> V_14 = V_77 ;
}
V_83 = F_33 ( V_1 , sizeof( T_1 ) , V_84 ) ;
if ( V_83 == NULL )
{
F_4 ( V_44 L_21 ) ;
return 0 ;
}
F_34 ( F_4 ( V_80 L_22 , V_1 -> V_40 , V_1 -> V_41 , V_48 -> V_49 ) ) ;
return 1 ;
}
int F_35 ( struct V_47 * V_48 , struct V_85 * V_86 )
{
T_1 * V_1 ;
char V_56 [ 100 ] ;
extern int V_87 ;
int V_88 , V_89 ;
F_19 ( F_4 ( L_23 , V_48 -> V_49 ) ) ;
V_56 [ 0 ] = 0 ;
if ( V_83 == NULL )
{
F_34 ( F_4 ( L_24 ) ) ;
return 0 ;
}
V_1 = V_83 ;
V_83 = NULL ;
if ( V_1 -> V_64 != V_48 -> V_49 )
{
F_19 ( F_4 ( L_25 ) ) ;
F_36 ( V_1 -> V_64 , 16 ) ;
return 0 ;
}
V_1 -> V_62 = V_48 -> V_75 ;
if ( ! ( ( V_1 -> V_62 & V_82 ) && ( V_1 -> V_62 & V_63 ) ) && V_48 -> V_18 > 0 )
{
int V_3 = ( V_1 -> V_62 & V_74 ) ? V_90 : 0 ;
if ( F_37 ( V_48 -> V_18 , F_13 , V_3 , L_26 , V_1 ) < 0 )
{
F_4 ( V_44 L_27 , V_48 -> V_18 ) ;
F_36 ( V_1 -> V_64 , 16 ) ;
return 0 ;
}
V_1 -> V_32 = 0 ;
if ( V_1 -> V_40 == 4 )
if ( ! F_26 ( V_1 , V_1 -> V_18 ) )
{
F_38 ( V_1 -> V_18 , V_1 ) ;
F_36 ( V_1 -> V_64 , 16 ) ;
return 0 ;
}
if ( ( V_1 -> type == 0 || V_1 -> type == V_34 ) &&
V_1 -> V_40 == 3 && V_1 -> V_41 == 1 )
{
if ( ( V_1 -> type != 0 && V_1 -> type != V_34 ) ||
! F_39 ( V_1 , V_48 ) )
{
if ( ( V_1 -> type != 0 && V_1 -> type != V_61 &&
V_1 -> type != V_79 ) || ! F_28 ( V_1 , V_48 ) )
{
F_19 ( F_4 ( L_28 ) ) ;
}
}
}
if ( V_1 -> V_40 == 4 && V_1 -> V_41 <= 11 )
V_1 -> V_32 = 1 ;
else
{
int V_91 ;
for ( V_91 = 0 ; V_91 < 3 && V_1 -> V_32 == 0 ; V_91 ++ )
{
if ( F_1 ( V_1 , 0xf2 ) )
{
int V_3 ;
for ( V_3 = 0 ; ! V_1 -> V_32 && V_3 < 10000 ; V_3 ++ ) ;
}
}
if ( ! V_1 -> V_32 )
F_4 ( V_9 L_29 , V_1 -> V_18 ) ;
else
{
F_19 ( F_4 ( L_30 , V_1 -> V_18 ) ) ;
}
}
}
V_92 = V_1 ;
switch ( V_1 -> V_40 )
{
case 1 :
V_1 -> V_14 = V_48 -> V_72 = V_93 ;
break;
case 2 :
if ( V_1 -> V_41 == 0 )
V_1 -> V_14 = V_48 -> V_72 = V_94 ;
else
V_1 -> V_14 = V_48 -> V_72 = V_95 ;
break;
case 3 :
switch ( V_1 -> V_14 ) {
case 0 :
V_1 -> V_14 = V_48 -> V_72 = V_96 ;
if ( V_48 -> V_56 == NULL )
V_48 -> V_56 = L_31 ;
break;
case V_34 :
F_40 ( V_1 , V_48 ) ;
break;
}
break;
case 4 :
V_1 -> V_14 = V_48 -> V_72 = V_15 ;
if ( ( V_1 -> V_41 == 2 ) && F_7 ( V_1 , 0x3c ) && F_7 ( V_1 , 0x4c ) )
{
V_89 = F_7 ( V_1 , 0x30 ) ;
F_24 ( V_1 , 0x22 , ( V_88 = F_7 ( V_1 , 0x22 ) ) & 0x0f ) ;
F_24 ( V_1 , 0x30 , 0xff ) ;
if ( ( F_7 ( V_1 , 0x30 ) != 0xff ) || ( ( F_7 ( V_1 , 0x22 ) & 0xf0 ) != 0x10 ) )
{
V_1 -> V_97 = V_98 ;
if ( V_48 -> V_56 == NULL )
V_48 -> V_56 = L_32 ;
}
else
{
F_24 ( V_1 , 0x3c , 0x1f ) ;
F_24 ( V_1 , 0x4c , 0x1f ) ;
F_24 ( V_1 , 0x22 , V_88 ) ;
V_1 -> V_97 = V_99 ;
if ( V_48 -> V_56 == NULL )
V_48 -> V_56 = L_33 ;
}
F_24 ( V_1 , 0x30 , V_89 ) ;
}
else if ( V_48 -> V_56 == NULL )
V_48 -> V_56 = L_34 ;
if ( V_48 -> V_60 == - 1 )
V_1 -> V_45 = V_1 -> V_43 ;
else if ( V_48 -> V_60 < 5 || V_48 -> V_60 > 7 )
{
F_4 ( V_9 L_35 ) ;
V_1 -> V_45 = V_1 -> V_43 ;
}
else
V_1 -> V_45 = V_48 -> V_60 ;
if( ! F_23 ( V_1 ) ) {
F_38 ( V_1 -> V_18 , V_1 ) ;
F_36 ( V_48 -> V_49 , 16 ) ;
return 0 ;
}
V_1 -> V_62 |= V_63 ;
}
if ( ! ( V_1 -> V_62 & V_100 ) )
if ( V_1 -> V_40 == 3 || V_1 -> V_40 == 4 )
F_41 ( V_1 , V_86 ) ;
if ( ! ( V_1 -> V_62 & V_63 ) )
F_42 ( V_1 , V_86 ) ;
if ( V_48 -> V_56 == NULL )
V_48 -> V_56 = L_36 ;
sprintf ( V_56 , L_37 , V_48 -> V_56 , V_1 -> V_40 , V_1 -> V_41 ) ;
F_43 ( V_56 , V_48 ) ;
if ( V_1 -> V_14 <= V_96 )
{
if ( V_1 -> V_40 == 3 && V_1 -> V_41 != 1 )
{
F_4 ( V_80 L_38 ) ;
F_4 ( V_80 L_39 ) ;
F_4 ( V_80 L_40 ) ;
F_4 ( V_80 L_41 ) ;
}
else if ( ! V_87 && V_1 -> V_14 == V_96 )
{
F_4 ( V_80 L_42 , V_1 -> V_40 , V_1 -> V_41 ) ;
F_4 ( V_80 L_43 ) ;
F_4 ( V_80 L_44 ) ;
}
}
V_48 -> V_72 = V_1 -> V_14 ;
V_48 -> V_101 [ 0 ] = V_1 -> V_23 ;
V_102 = V_1 ;
if ( ! ( V_1 -> V_62 & V_82 ) && V_1 -> V_43 >= 0 )
{
if ( F_44 ( V_1 -> V_43 , L_45 ) )
{
F_4 ( V_9 L_46 , V_1 -> V_43 ) ;
}
if ( V_1 -> V_45 >= 0 && V_1 -> V_45 != V_1 -> V_43 )
{
if ( F_44 ( V_1 -> V_45 , L_47 ) )
F_4 ( V_9 L_48 , V_1 -> V_45 ) ;
}
F_45 ( V_1 , V_56 , V_86 ) ;
V_48 -> V_101 [ 0 ] = V_1 -> V_23 ;
}
else
{
F_34 ( F_4 ( L_49 ) ) ;
}
return 1 ;
}
void F_46 ( struct V_47 * V_48 , int V_103 )
{
T_1 * V_1 ;
V_1 = V_104 [ V_48 -> V_101 [ 0 ] ] -> V_1 ;
if ( V_1 && V_1 -> V_64 == V_48 -> V_49 )
{
if ( ( V_1 -> V_14 & V_34 ) && V_1 -> V_30 )
F_36 ( V_1 -> V_30 , 8 ) ;
F_36 ( V_1 -> V_64 , 16 ) ;
if ( ! ( V_1 -> V_62 & V_82 ) )
{
F_47 ( V_1 -> V_43 ) ;
if ( V_1 -> V_45 >= 0 )
F_47 ( V_1 -> V_45 ) ;
}
if ( ! ( V_1 -> V_62 & V_82 && V_1 -> V_62 & V_63 ) )
{
if ( V_1 -> V_18 > 0 )
F_38 ( V_1 -> V_18 , V_1 ) ;
F_48 ( V_1 ) ;
if ( ! V_103 )
F_49 ( V_1 -> V_70 ) ;
F_50 ( V_1 -> V_23 ) ;
}
F_51 ( V_1 ) ;
}
else
F_36 ( V_48 -> V_49 , 16 ) ;
F_51 ( V_83 ) ;
}
void F_24 ( T_1 * V_1 , unsigned int V_105 , unsigned int V_106 )
{
unsigned long V_38 ;
if ( V_1 -> V_14 == V_34 ) {
F_52 ( V_1 , V_105 , V_106 ) ;
return;
}
F_21 ( & V_1 -> V_39 , V_38 ) ;
F_3 ( ( ( unsigned char ) ( V_105 & 0xff ) ) , V_107 ) ;
F_18 ( 20 ) ;
F_3 ( ( ( unsigned char ) ( V_106 & 0xff ) ) , V_108 ) ;
F_18 ( 20 ) ;
F_22 ( & V_1 -> V_39 , V_38 ) ;
}
unsigned int F_7 ( T_1 * V_1 , unsigned int V_105 )
{
unsigned int V_2 ;
unsigned long V_38 ;
if ( V_1 -> V_14 == V_34 ) return F_53 ( V_1 , V_105 ) ;
F_21 ( & V_1 -> V_39 , V_38 ) ;
F_3 ( ( ( unsigned char ) ( V_105 & 0xff ) ) , V_107 ) ;
F_18 ( 20 ) ;
V_2 = F_2 ( V_108 ) ;
F_18 ( 20 ) ;
F_22 ( & V_1 -> V_39 , V_38 ) ;
return V_2 ;
}
void F_54
( T_1 * V_1 , unsigned int V_109 , unsigned int V_110 , unsigned int V_2 )
{
int V_106 ;
V_106 = F_7 ( V_1 , V_109 ) ;
V_106 = ( V_106 & ~ V_110 ) | ( V_2 & V_110 ) ;
F_24 ( V_1 , V_109 , V_106 ) ;
}
static void F_55 ( T_1 * V_1 , int V_64 , int V_111 , unsigned char V_2 )
{
unsigned long V_38 ;
F_21 ( & V_55 , V_38 ) ;
F_3 ( ( V_111 & 0xff ) , V_64 + 1 ) ;
F_3 ( ( V_111 >> 8 ) , V_64 + 2 ) ;
F_3 ( ( V_2 ) , V_64 ) ;
F_22 ( & V_55 , V_38 ) ;
}
static unsigned char F_56 ( T_1 * V_1 , int V_64 , int V_111 )
{
unsigned long V_38 ;
unsigned char V_2 ;
F_21 ( & V_55 , V_38 ) ;
F_3 ( ( V_111 & 0xff ) , V_64 + 1 ) ;
F_3 ( ( V_111 >> 8 ) , V_64 + 2 ) ;
V_2 = F_2 ( V_64 ) ;
F_22 ( & V_55 , V_38 ) ;
return V_2 ;
}
static int F_57 ( T_1 * V_1 , struct V_47 * V_48 )
{
int V_112 = V_48 -> V_49 ;
int V_113 = V_112 + 4 ;
int V_3 ;
unsigned char V_114 ;
V_114 = F_2 ( V_112 + 7 ) ;
F_3 ( ( V_114 | 3 ) , V_112 + 7 ) ;
F_3 ( ( ( V_114 & 0xfe ) | 2 ) , V_112 + 7 ) ;
F_58 ( 3 ) ;
F_3 ( ( V_114 & 0xfc ) , V_112 + 7 ) ;
F_55 ( V_1 , V_113 , 0 , 0x00 ) ;
F_55 ( V_1 , V_113 , 1 , 0xff ) ;
F_18 ( 10 ) ;
if ( F_56 ( V_1 , V_113 , 0 ) != 0x00 || F_56 ( V_1 , V_113 , 1 ) != 0xff )
{
F_19 ( F_4 ( L_50 , F_56 ( V_1 , V_113 , 0 ) , F_56 ( V_1 , V_113 , 1 ) ) ) ;
return 0 ;
}
V_1 -> V_14 = V_79 ;
F_59 ( V_1 ) ;
#ifdef F_32
if ( ! V_115 )
{
V_116 = F_60 ( L_51 , ( void * ) & V_115 ) ;
V_117 = V_115 ;
}
#endif
if ( V_116 > 0 )
{
if ( V_116 != 8192 )
{
F_4 ( V_44 L_52 ) ;
return 1 ;
}
for ( V_3 = 0 ; V_3 < 8192 ; V_3 ++ )
F_55 ( V_1 , V_113 , V_3 , V_115 [ V_3 ] ) ;
for ( V_3 = 0 ; V_3 < 8192 ; V_3 ++ )
if ( F_56 ( V_1 , V_113 , V_3 ) != V_115 [ V_3 ] )
{
F_4 ( V_44 L_53 ) ;
return 0 ;
}
}
V_114 = 0 ;
#ifdef F_61
{
static unsigned char V_118 [] = {
0 , 0 , 3 , 1 , 0 , 0 , 0 , 0 , 0 , 3 , 2 , 0 , 0 , 0 , 0 , 0
} ;
V_114 |= V_118 [ F_61 ] << 6 ;
}
#endif
#ifdef F_62
V_114 |= 0x10 ;
#endif
F_3 ( ( V_114 | 0x03 ) , V_112 + 7 ) ;
V_48 -> V_56 = L_54 ;
return 1 ;
}
static int F_63 ( T_1 * V_1 , struct V_47 * V_48 )
{
int V_112 = V_48 -> V_49 ;
int V_119 = V_1 -> V_64 ;
int V_18 = V_48 -> V_18 ;
unsigned char V_42 = 0 ;
unsigned long V_38 ;
if ( V_18 < 0 )
V_18 *= - 1 ;
if ( V_18 < 1 || V_18 > 15 ||
V_57 [ V_18 ] == 0 )
{
F_4 ( V_44 L_55 , V_18 ) ;
return 0 ;
}
switch ( V_119 )
{
case 0x220 :
V_42 = 1 ;
break;
case 0x240 :
V_42 = 2 ;
break;
case 0x260 :
V_42 = 3 ;
break;
default:
return 0 ;
}
V_42 = V_54 = V_42 << 5 ;
switch ( V_112 )
{
case 0x310 :
V_42 |= 1 ;
break;
case 0x320 :
V_42 |= 2 ;
break;
case 0x330 :
V_42 |= 3 ;
break;
default:
F_4 ( V_44 L_56 , V_112 ) ;
return 0 ;
}
F_21 ( & V_55 , V_38 ) ;
F_3 ( 0xAF , 0x201 ) ;
F_3 ( 0x50 , 0x201 ) ;
F_3 ( V_42 , 0x201 ) ;
F_22 ( & V_55 , V_38 ) ;
V_48 -> V_56 = L_14 ;
F_57 ( V_1 , V_48 ) ;
if ( ! F_1 ( V_1 , 0xfb ) )
return 0 ;
if ( ! F_1 ( V_1 , V_59 [ V_1 -> V_43 ] |
( V_59 [ V_1 -> V_45 ] << 4 ) ) )
return 0 ;
if ( ! F_1 ( V_1 , V_57 [ V_1 -> V_18 ] |
( V_57 [ V_18 ] << 4 ) ) )
return 0 ;
return 1 ;
}
int F_64 ( struct V_47 * V_48 , struct V_85 * V_86 )
{
T_1 * V_1 = V_102 ;
int V_120 ;
if ( V_102 == NULL )
return 0 ;
V_102 = NULL ;
if ( V_48 -> V_49 <= 0 )
{
if( V_1 -> V_14 == V_15 && V_1 -> V_41 >= 12 )
{
unsigned char V_42 = F_7 ( V_1 , 0x84 ) & ~ 0x06 ;
F_24 ( V_1 , 0x84 , V_42 | 0x02 ) ;
}
return 0 ;
}
#if F_65 ( V_121 )
if ( V_1 -> V_14 == V_34 )
{
struct V_122 * V_123 ;
V_123 = F_66 ( V_48 -> V_49 , 2 , L_57 ) ;
if ( ! V_123 ) {
F_4 ( V_44 L_58 , V_48 -> V_49 ) ;
return 0 ;
}
if ( ! F_67 ( V_1 , V_48 ) ) {
F_36 ( V_48 -> V_49 , 2 ) ;
return 0 ;
}
V_48 -> V_56 = L_59 ;
V_1 -> V_17 = NULL ;
if ( ! F_68 ( V_48 , V_123 ) ) {
F_36 ( V_48 -> V_49 , 2 ) ;
return 0 ;
}
F_69 ( V_48 , V_86 ) ;
if ( V_92 -> V_18 == - V_48 -> V_18 )
V_92 -> V_17 =
( void * ) ( long ) V_48 -> V_101 [ 1 ] ;
return 1 ;
}
#endif
switch ( V_1 -> V_14 )
{
case V_15 :
if ( V_48 -> V_49 != 0x300 && V_48 -> V_49 != 0x330 )
{
F_4 ( V_44 L_60 , V_48 -> V_49 ) ;
return 0 ;
}
V_48 -> V_56 = L_34 ;
if ( V_48 -> V_18 < 3 || V_48 -> V_18 == V_1 -> V_18 )
V_48 -> V_18 = - V_1 -> V_18 ;
if ( V_1 -> V_41 > 12 )
F_25 ( V_1 , V_48 ) ;
break;
case V_61 :
if ( V_48 -> V_18 < 3 || V_48 -> V_18 == V_1 -> V_18 )
V_48 -> V_18 = - V_1 -> V_18 ;
if ( ! F_63 ( V_1 , V_48 ) )
return 0 ;
break;
case V_77 :
V_48 -> V_56 = L_61 ;
F_4 ( L_62 ) ;
break;
default:
return 0 ;
}
V_120 = F_70 ( V_48 , V_86 ) ;
if ( V_120 )
V_92 -> V_17 = V_124 [ V_48 -> V_101 [ 4 ] ] -> V_1 ;
return V_120 ;
}
void F_71 ( struct V_47 * V_48 )
{
#if F_65 ( V_121 )
if ( ! strcmp ( V_48 -> V_56 , L_59 ) ) {
F_72 ( V_48 ) ;
return;
}
#endif
F_73 ( V_48 ) ;
}
