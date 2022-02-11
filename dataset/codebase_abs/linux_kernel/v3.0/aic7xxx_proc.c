static void
F_1 ( const char * V_1 , ... )
{
T_1 V_2 ;
char V_3 [ 256 ] ;
va_start ( V_2 , V_1 ) ;
vsprintf ( V_3 , V_1 , V_2 ) ;
F_2 ( V_3 ) ;
va_end ( V_2 ) ;
}
static int
F_3 ( char * V_4 , int V_5 , struct V_6 * V_7 )
{
F_1 ( L_1 , V_4 ) ;
return ( - V_8 ) ;
}
int
F_4 ( struct V_6 * V_7 , char * V_4 , char * * V_9 , T_2 V_10 , int V_5 ,
int V_11 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
int V_18 = 0 ;
unsigned char V_19 ;
unsigned char V_20 ;
for( V_13 = V_21 ; V_13 && V_13 -> V_22 != V_7 ; V_13 = V_13 -> V_23 )
;
if ( ! V_13 )
{
V_18 += sprintf ( V_4 , L_2 , V_7 -> V_24 ) ;
if ( V_18 > V_5 )
{
return ( V_18 ) ;
}
else
{
return ( V_5 ) ;
}
}
if ( V_11 == TRUE )
{
return ( F_3 ( V_4 , V_5 , V_7 ) ) ;
}
V_13 = (struct V_12 * ) V_7 -> V_25 ;
V_18 = 4096 ;
F_5 (aic_dev, &p->aic_devs, list)
V_18 += 512 ;
if ( V_26 != V_18 )
{
if ( V_27 != NULL )
{
F_6 ( V_27 ) ;
V_26 = 0 ;
}
V_27 = F_7 ( V_18 , V_28 ) ;
}
if ( V_27 == NULL )
{
V_18 = sprintf ( V_4 , L_3 ,
__LINE__ ) ;
return V_18 ;
}
V_26 = V_18 ;
V_18 = 0 ;
V_18 += sprintf ( V_29 , L_4 ) ;
V_18 += sprintf ( V_29 , L_5 , V_30 ) ;
V_18 += sprintf ( V_29 , L_6 , V_31 ) ;
V_18 += sprintf ( V_29 , L_7 ) ;
V_18 += sprintf ( V_29 , L_8 ) ;
V_18 += sprintf ( V_29 , L_9 ,
V_32 [ V_13 -> V_33 ] ) ;
if ( V_13 -> V_34 & V_35 )
V_18 += sprintf ( V_29 , L_10 ) ;
else
{
char * V_36 = L_11 ;
char * V_37 = L_11 ;
char * V_38 = L_12 ;
if ( V_13 -> V_34 & V_39 )
{
V_36 = L_13 ;
if ( V_13 -> V_34 & ( V_40 | V_41 ) )
V_36 = ( V_13 -> V_34 & V_40 ) ? L_14 : L_15 ;
}
if ( V_13 -> V_42 & V_43 )
V_38 = L_16 ;
if ( V_13 -> V_42 & V_44 )
{
switch( V_13 -> V_45 & V_46 )
{
case V_47 :
case V_48 :
V_37 = L_17 ;
break;
default:
V_37 = L_18 ;
break;
}
}
else if ( V_13 -> V_42 & V_49 )
V_37 = L_19 ;
else if ( V_13 -> V_42 & V_50 )
V_37 = L_20 ;
V_18 += sprintf ( V_29 , L_21 ,
V_37 , V_38 , V_36 ) ;
}
switch( V_13 -> V_45 & ~ V_46 )
{
case V_51 :
V_18 += sprintf ( V_29 , L_22 , V_13 -> V_52 ) ;
break;
case V_53 :
V_18 += sprintf ( V_29 , L_23 , V_13 -> V_52 ) ;
break;
default:
V_18 += sprintf ( V_29 , L_24 , V_13 -> V_54 ,
F_8 ( V_13 -> V_52 ) , F_9 ( V_13 -> V_52 ) ) ;
break;
}
if( ! ( V_13 -> V_55 ) )
{
V_18 += sprintf ( V_29 , L_25 , V_13 -> V_56 ) ;
}
else
{
V_18 += sprintf ( V_29 , L_26 , V_13 -> V_57 ) ;
}
if( ( V_13 -> V_45 & ( V_51 | V_53 ) ) )
{
V_18 += sprintf ( V_29 , L_27 , V_13 -> V_58 ) ;
}
V_18 += sprintf ( V_29 , L_28 ,
( V_13 -> V_34 & V_59 ) ? L_29 :
( ( V_13 -> V_34 & V_60 ) ? L_30 :
L_31 ) ) ;
V_18 += sprintf ( V_29 , L_32 ,
( V_13 -> V_34 & V_61 ) ? L_33 : L_34 ) ;
V_18 += sprintf ( V_29 , L_35 , V_7 -> V_62 ) ;
V_18 += sprintf ( V_29 , L_36 ,
V_13 -> V_63 , V_13 -> V_64 ) ;
V_18 += sprintf ( V_29 , L_37
L_38 , V_13 -> V_65 -> V_66 , V_13 -> V_65 -> V_67 ,
V_13 -> V_65 -> V_68 ) ;
if ( V_13 -> V_34 & V_69 )
V_18 += sprintf ( V_29 , L_39 ) ;
V_18 += sprintf ( V_29 , L_40 , V_13 -> V_70 ) ;
if ( V_13 -> V_45 & V_53 )
{
V_18 += sprintf ( V_29 , L_41 ,
( V_13 -> V_71 & V_72 ) ? L_42 : L_43 ) ;
}
else
{
V_18 += sprintf ( V_29 , L_7 ) ;
}
V_18 += sprintf ( V_29 , L_44 ,
V_13 -> V_73 ) ;
V_18 += sprintf ( V_29 , L_45 ,
V_13 -> V_74 ) ;
V_18 += sprintf ( V_29 , L_46 ,
( V_13 -> V_34 & V_75 ) ? L_47 : L_48 ) ;
V_18 += sprintf ( V_29 , L_49 , V_13 -> V_76 ) ;
if ( V_13 -> V_42 & ( V_50 | V_49 ) )
{
V_18 += sprintf ( V_29 , L_50 , V_13 -> V_77 ) ;
}
V_18 += sprintf ( V_29 , L_51 , V_78 ) ;
V_18 += sprintf ( V_29 , L_52
L_53 , V_13 -> V_79 ) ;
V_18 += sprintf ( V_29 , L_54 ) ;
for( V_19 = 0 ; V_19 < ( V_80 - 1 ) ; V_19 ++ )
V_18 += sprintf ( V_29 , L_55 , V_81 [ V_13 -> V_79 ] . V_82 [ V_19 ] ) ;
V_18 += sprintf ( V_29 , L_56 , V_81 [ V_13 -> V_79 ] . V_82 [ V_19 ] ) ;
V_18 += sprintf ( V_29 , L_7 ) ;
V_18 += sprintf ( V_29 , L_57 ) ;
F_5 (aic_dev, &p->aic_devs, list)
{
V_17 = V_15 -> V_83 ;
V_20 = V_17 -> V_36 << 3 | V_17 -> V_84 ;
V_18 += sprintf ( V_29 , L_58 ,
V_13 -> V_24 , V_17 -> V_36 , V_17 -> V_84 , V_17 -> V_85 ) ;
V_18 += sprintf ( V_29 , L_59 ,
( V_15 -> V_86 . V_87 == V_88 ) ?
L_60 : L_61 ,
( V_15 -> V_86 . V_10 != 0 ) ?
L_62 : L_63 ) ;
if ( V_15 -> V_86 . V_10 != 0 )
{
struct V_89 * V_90 ;
unsigned char V_91 = V_15 -> V_86 . V_91 ;
int V_92 = V_15 -> V_86 . V_92 ;
int V_93 = ( V_15 -> V_86 . V_87 ==
V_88 ) ? 1 : 0 ;
V_90 = F_10 ( V_13 , & V_92 , 0 , & V_91 ) ;
if ( V_90 != NULL )
{
V_18 += sprintf ( V_29 , L_64 ,
V_90 -> V_93 [ V_93 ] ,
V_15 -> V_86 . V_10 ) ;
}
else
{
V_18 += sprintf ( V_29 , L_65 ,
V_15 -> V_86 . V_10 ) ;
}
}
V_18 += sprintf ( V_29 , L_66 ) ;
V_18 += sprintf ( V_29 , L_67 ,
V_15 -> V_86 . V_92 ,
V_15 -> V_86 . V_10 ,
V_15 -> V_86 . V_87 ,
V_15 -> V_86 . V_91 ) ;
V_18 += sprintf ( V_29 , L_68 ,
V_15 -> V_94 . V_92 ,
V_15 -> V_94 . V_10 ,
V_15 -> V_94 . V_87 ,
V_15 -> V_94 . V_91 ) ;
V_18 += sprintf ( V_29 , L_69 ,
V_13 -> V_95 [ V_20 ] . V_92 ,
V_13 -> V_95 [ V_20 ] . V_10 ,
V_13 -> V_95 [ V_20 ] . V_87 ,
V_13 -> V_95 [ V_20 ] . V_91 ) ;
if( V_17 -> V_96 )
{
V_18 += sprintf ( V_29 , L_70 , V_17 -> V_97 ? L_33 : L_34 , V_17 -> V_98 , V_15 -> V_99 ) ;
}
if( V_15 -> V_100 )
V_18 += sprintf ( V_29 , L_71 ,
V_15 -> V_101 + V_15 -> V_102 , V_15 -> V_101 , V_15 -> V_102 ,
V_15 -> V_100 , V_15 -> V_103 ) ;
else
V_18 += sprintf ( V_29 , L_72 ,
V_15 -> V_101 + V_15 -> V_102 , V_15 -> V_101 , V_15 -> V_102 ) ;
V_18 += sprintf ( V_29 , L_73 , V_104 ) ;
V_18 += sprintf ( V_29 , L_74 ) ;
for ( V_19 = 0 ; V_19 < F_11 ( V_15 -> V_105 ) ; V_19 ++ )
{
V_18 += sprintf ( V_29 , L_75 , V_15 -> V_105 [ V_19 ] ) ;
}
V_18 += sprintf ( V_29 , L_7 ) ;
V_18 += sprintf ( V_29 , L_76 ) ;
for ( V_19 = 0 ; V_19 < F_11 ( V_15 -> V_106 ) ; V_19 ++ )
{
V_18 += sprintf ( V_29 , L_75 , V_15 -> V_106 [ V_19 ] ) ;
}
V_18 += sprintf ( V_29 , L_7 ) ;
V_18 += sprintf ( V_29 , L_77 ) ;
}
if ( V_18 >= V_26 )
{
F_2 ( V_107 L_78 ) ;
}
if ( V_10 > V_18 - 1 )
{
F_6 ( V_27 ) ;
V_27 = NULL ;
V_26 = V_5 = 0 ;
* V_9 = NULL ;
}
else
{
* V_9 = V_4 ;
V_5 = F_12 ( int , V_5 , V_18 - V_10 ) ;
memcpy ( V_4 , & V_27 [ V_10 ] , V_5 ) ;
}
return ( V_5 ) ;
}
