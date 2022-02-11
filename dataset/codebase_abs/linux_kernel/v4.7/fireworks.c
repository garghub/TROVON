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
if ( V_7 -> type == V_63 )
V_2 -> V_64 = true ;
if ( V_7 -> type == V_65 ||
V_7 -> type == V_66 ||
V_7 -> type == V_63 ||
V_7 -> type == V_67 ||
V_7 -> type == V_68 )
V_2 -> V_69 = true ;
V_12:
F_7 ( V_7 ) ;
return V_9 ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
F_11 ( V_2 -> V_5 ) ;
F_7 ( V_2 -> V_70 ) ;
F_12 ( & V_2 -> V_71 ) ;
F_7 ( V_2 ) ;
}
static void
F_13 ( struct V_72 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_73 ;
if ( V_2 -> V_74 >= 0 ) {
F_14 ( & V_75 ) ;
F_15 ( V_2 -> V_74 , V_76 ) ;
F_16 ( & V_75 ) ;
}
F_8 ( V_15 -> V_73 ) ;
}
static void
F_17 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = F_18 ( V_78 , struct V_1 , V_79 . V_78 ) ;
unsigned int V_74 ;
int V_9 ;
if ( V_2 -> V_80 )
return;
F_14 ( & V_75 ) ;
for ( V_74 = 0 ; V_74 < V_81 ; ++ V_74 ) {
if ( ! F_19 ( V_74 , V_76 ) && V_82 [ V_74 ] )
break;
}
if ( V_74 >= V_81 ) {
F_16 ( & V_75 ) ;
return;
}
V_9 = F_20 ( & V_2 -> V_5 -> V_24 , V_83 [ V_74 ] ,
V_84 [ V_74 ] , V_85 , 0 , & V_2 -> V_15 ) ;
if ( V_9 < 0 ) {
F_16 ( & V_75 ) ;
return;
}
V_86 = F_21 ( V_86 ,
V_87 , 4096U ) ;
V_2 -> V_70 = F_3 ( V_86 , V_10 ) ;
if ( V_2 -> V_70 == NULL ) {
V_9 = - V_11 ;
goto error;
}
V_2 -> V_88 = V_2 -> V_89 = V_2 -> V_70 ;
F_22 ( V_2 ) ;
V_9 = F_1 ( V_2 ) ;
if ( V_9 < 0 )
goto error;
V_9 = F_23 ( V_2 ) ;
if ( V_9 < 0 )
goto error;
F_24 ( V_2 ) ;
if ( V_2 -> V_40 || V_2 -> V_42 ) {
V_9 = F_25 ( V_2 ) ;
if ( V_9 < 0 )
goto error;
}
V_9 = F_26 ( V_2 ) ;
if ( V_9 < 0 )
goto error;
V_9 = F_27 ( V_2 ) ;
if ( V_9 < 0 )
goto error;
V_9 = F_28 ( V_2 -> V_15 ) ;
if ( V_9 < 0 )
goto error;
F_29 ( V_74 , V_76 ) ;
F_16 ( & V_75 ) ;
V_2 -> V_15 -> V_90 = F_13 ;
V_2 -> V_15 -> V_73 = V_2 ;
V_2 -> V_80 = true ;
return;
error:
F_16 ( & V_75 ) ;
F_10 ( V_2 ) ;
F_9 ( V_2 ) ;
F_30 ( V_2 -> V_15 ) ;
F_31 ( & V_2 -> V_5 -> V_24 ,
L_4 , V_9 ) ;
}
static int
F_32 ( struct V_91 * V_5 , const struct V_92 * V_93 )
{
struct V_1 * V_2 ;
V_2 = F_3 ( sizeof( struct V_1 ) , V_10 ) ;
if ( V_2 == NULL )
return - V_11 ;
V_2 -> V_5 = F_33 ( V_5 ) ;
F_34 ( & V_5 -> V_24 , V_2 ) ;
F_35 ( & V_2 -> V_71 ) ;
F_36 ( & V_2 -> V_94 ) ;
F_37 ( & V_2 -> V_95 ) ;
F_38 ( & V_2 -> V_79 , F_17 ) ;
F_39 ( V_5 , & V_2 -> V_79 ) ;
return 0 ;
}
static void F_40 ( struct V_91 * V_5 )
{
struct V_1 * V_2 = F_41 ( & V_5 -> V_24 ) ;
if ( ! V_2 -> V_80 )
F_39 ( V_5 , & V_2 -> V_79 ) ;
F_42 ( V_2 -> V_5 ) ;
if ( V_2 -> V_80 ) {
F_14 ( & V_2 -> V_71 ) ;
F_43 ( V_2 ) ;
F_16 ( & V_2 -> V_71 ) ;
}
}
static void F_44 ( struct V_91 * V_5 )
{
struct V_1 * V_2 = F_41 ( & V_5 -> V_24 ) ;
F_45 ( & V_2 -> V_79 ) ;
if ( V_2 -> V_80 ) {
F_46 ( V_2 -> V_15 ) ;
} else {
F_8 ( V_2 ) ;
}
}
static int T_1 F_47 ( void )
{
int V_9 ;
V_9 = F_48 () ;
if ( V_9 < 0 )
goto V_12;
V_9 = F_49 ( & V_96 . V_16 ) ;
if ( V_9 < 0 )
F_50 () ;
V_12:
return V_9 ;
}
static void T_2 F_51 ( void )
{
F_50 () ;
F_52 ( & V_96 . V_16 ) ;
}
