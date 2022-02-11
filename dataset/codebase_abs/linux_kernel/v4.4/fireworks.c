static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_6 * V_7 ;
char V_8 [ 12 ] = { 0 } ;
int V_9 ;
V_7 = F_3 ( sizeof( struct V_6 ) , V_10 ) ;
if ( V_7 == NULL )
return - V_11 ;
V_9 = F_4 ( V_2 , V_7 ) ;
if ( V_9 < 0 )
goto V_12;
snprintf ( V_8 , sizeof( V_8 ) , L_1 ,
( V_7 -> V_13 >> 24 ) & 0xff ,
( V_7 -> V_13 >> 16 ) & 0xff ) ;
V_2 -> V_14 = V_7 -> V_13 ;
strcpy ( V_2 -> V_15 -> V_16 , L_2 ) ;
strcpy ( V_2 -> V_15 -> V_17 , V_7 -> V_18 ) ;
strcpy ( V_2 -> V_15 -> V_19 , V_7 -> V_18 ) ;
snprintf ( V_2 -> V_15 -> V_20 , sizeof( V_2 -> V_15 -> V_20 ) ,
L_3 ,
V_7 -> V_21 , V_7 -> V_18 , V_8 ,
V_7 -> V_22 , V_7 -> V_23 ,
F_5 ( & V_2 -> V_5 -> V_24 ) , 100 << V_4 -> V_25 ) ;
if ( V_7 -> V_26 & F_6 ( V_27 ) )
V_2 -> V_28 = true ;
V_2 -> V_29 = 0 ;
if ( ( V_7 -> V_30 <= 22050 )
&& ( 22050 <= V_7 -> V_31 ) )
V_2 -> V_29 |= V_32 ;
if ( ( V_7 -> V_30 <= 32000 )
&& ( 32000 <= V_7 -> V_31 ) )
V_2 -> V_29 |= V_33 ;
if ( ( V_7 -> V_30 <= 44100 )
&& ( 44100 <= V_7 -> V_31 ) )
V_2 -> V_29 |= V_34 ;
if ( ( V_7 -> V_30 <= 48000 )
&& ( 48000 <= V_7 -> V_31 ) )
V_2 -> V_29 |= V_35 ;
if ( ( V_7 -> V_30 <= 88200 )
&& ( 88200 <= V_7 -> V_31 ) )
V_2 -> V_29 |= V_36 ;
if ( ( V_7 -> V_30 <= 96000 )
&& ( 96000 <= V_7 -> V_31 ) )
V_2 -> V_29 |= V_37 ;
if ( ( V_7 -> V_30 <= 176400 )
&& ( 176400 <= V_7 -> V_31 ) )
V_2 -> V_29 |= V_38 ;
if ( ( V_7 -> V_30 <= 192000 )
&& ( 192000 <= V_7 -> V_31 ) )
V_2 -> V_29 |= V_39 ;
if ( V_7 -> V_40 > V_41 ||
V_7 -> V_42 > V_43 ) {
V_9 = - V_44 ;
goto V_12;
}
V_2 -> V_40 = V_7 -> V_40 ;
V_2 -> V_42 = V_7 -> V_42 ;
if ( V_7 -> V_45 > V_46 ||
V_7 -> V_47 > V_46 ||
V_7 -> V_48 > V_46 ||
V_7 -> V_49 > V_46 ||
V_7 -> V_50 > V_46 ||
V_7 -> V_51 > V_46 ) {
V_9 = - V_52 ;
goto V_12;
}
V_2 -> V_53 [ 0 ] = V_7 -> V_45 ;
V_2 -> V_53 [ 1 ] = V_7 -> V_47 ;
V_2 -> V_53 [ 2 ] = V_7 -> V_48 ;
V_2 -> V_54 [ 0 ] = V_7 -> V_49 ;
V_2 -> V_54 [ 1 ] = V_7 -> V_50 ;
V_2 -> V_54 [ 2 ] = V_7 -> V_51 ;
if ( V_7 -> V_55 > V_56 ||
V_7 -> V_57 > V_56 ) {
V_9 = - V_44 ;
goto V_12;
}
V_2 -> V_58 = V_7 -> V_58 ;
V_2 -> V_59 = V_7 -> V_59 ;
V_2 -> V_55 = V_7 -> V_55 ;
V_2 -> V_57 = V_7 -> V_57 ;
memcpy ( & V_2 -> V_60 , V_7 -> V_60 ,
sizeof( struct V_61 ) * V_7 -> V_55 ) ;
memcpy ( & V_2 -> V_62 , V_7 -> V_62 ,
sizeof( struct V_61 ) * V_7 -> V_57 ) ;
V_12:
F_7 ( V_7 ) ;
return V_9 ;
}
static void
F_8 ( struct V_63 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_64 ;
F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
F_11 ( V_2 -> V_5 ) ;
F_7 ( V_2 -> V_65 ) ;
if ( V_2 -> V_66 >= 0 ) {
F_12 ( & V_67 ) ;
F_13 ( V_2 -> V_66 , V_68 ) ;
F_14 ( & V_67 ) ;
}
F_15 ( & V_2 -> V_69 ) ;
}
static int
F_16 ( struct V_70 * V_5 ,
const struct V_71 * V_72 )
{
struct V_63 * V_15 ;
struct V_1 * V_2 ;
int V_66 , V_9 ;
F_12 ( & V_67 ) ;
for ( V_66 = 0 ; V_66 < V_73 ; ++ V_66 ) {
if ( ! F_17 ( V_66 , V_68 ) && V_74 [ V_66 ] )
break;
}
if ( V_66 >= V_73 ) {
V_9 = - V_75 ;
goto V_12;
}
V_9 = F_18 ( & V_5 -> V_24 , V_76 [ V_66 ] , V_77 [ V_66 ] ,
V_78 , sizeof( struct V_1 ) , & V_15 ) ;
if ( V_9 < 0 )
goto V_12;
V_2 = V_15 -> V_64 ;
V_2 -> V_66 = V_66 ;
F_19 ( V_66 , V_68 ) ;
V_15 -> V_79 = F_8 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_5 = F_20 ( V_5 ) ;
F_21 ( & V_2 -> V_69 ) ;
F_22 ( & V_2 -> V_80 ) ;
F_23 ( & V_2 -> V_81 ) ;
V_82 = F_24 ( V_82 ,
V_83 , 4096U ) ;
V_2 -> V_65 = F_3 ( V_82 , V_10 ) ;
if ( V_2 -> V_65 == NULL ) {
V_9 = - V_11 ;
goto error;
}
V_2 -> V_84 = V_2 -> V_85 = V_2 -> V_65 ;
F_25 ( V_2 ) ;
V_9 = F_1 ( V_2 ) ;
if ( V_9 < 0 )
goto error;
if ( V_72 -> V_86 == V_87 )
V_2 -> V_88 = true ;
if ( V_72 -> V_86 == V_89 ||
V_72 -> V_86 == V_90 ||
V_72 -> V_86 == V_87 ||
V_72 -> V_86 == V_91 ||
V_72 -> V_86 == V_92 )
V_2 -> V_93 = true ;
F_26 ( V_2 ) ;
if ( V_2 -> V_40 || V_2 -> V_42 ) {
V_9 = F_27 ( V_2 ) ;
if ( V_9 < 0 )
goto error;
}
V_9 = F_28 ( V_2 ) ;
if ( V_9 < 0 )
goto error;
V_9 = F_29 ( V_2 ) ;
if ( V_9 < 0 )
goto error;
V_9 = F_30 ( V_2 ) ;
if ( V_9 < 0 )
goto error;
V_9 = F_31 ( V_15 ) ;
if ( V_9 < 0 ) {
F_9 ( V_2 ) ;
goto error;
}
F_32 ( & V_5 -> V_24 , V_2 ) ;
V_12:
F_14 ( & V_67 ) ;
return V_9 ;
error:
F_10 ( V_2 ) ;
F_14 ( & V_67 ) ;
F_33 ( V_15 ) ;
return V_9 ;
}
static void F_34 ( struct V_70 * V_5 )
{
struct V_1 * V_2 = F_35 ( & V_5 -> V_24 ) ;
F_36 ( V_2 -> V_5 ) ;
F_37 ( V_2 ) ;
}
static void F_38 ( struct V_70 * V_5 )
{
struct V_1 * V_2 = F_35 ( & V_5 -> V_24 ) ;
F_39 ( V_2 -> V_15 ) ;
}
static int T_1 F_40 ( void )
{
int V_9 ;
V_9 = F_41 () ;
if ( V_9 < 0 )
goto V_12;
V_9 = F_42 ( & V_94 . V_16 ) ;
if ( V_9 < 0 )
F_43 () ;
V_12:
return V_9 ;
}
static void T_2 F_44 ( void )
{
F_43 () ;
F_45 ( & V_94 . V_16 ) ;
}
