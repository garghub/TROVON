static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 [ 4 ] ;
T_1 V_4 = 0 ;
V_3 [ V_4 ++ ] = F_2 ( V_2 -> V_5 -> V_6 ) | 1 ;
V_3 [ V_4 ++ ] = V_7 ;
V_3 [ V_4 ++ ] = V_8 ;
V_3 [ V_4 ++ ] = V_8 ;
return V_2 -> V_9 -> V_10 ( V_2 ,
& V_3 [ 0 ] , V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
T_1 V_11 , T_1 * V_12 )
{
int V_13 ;
T_1 V_3 [ 6 ] ;
T_1 V_4 = 0 ;
V_3 [ V_4 ++ ] = V_14 ;
V_3 [ V_4 ++ ] = V_8 ;
V_3 [ V_4 ++ ] = V_15 ;
V_3 [ V_4 ++ ] = V_8 ;
V_3 [ V_4 ++ ] = V_8 ;
V_13 = V_2 -> V_9 -> V_10 ( V_2 ,
& V_3 [ 0 ] , V_4 ) ;
if ( V_13 )
return V_13 ;
V_13 = V_2 -> V_9 -> V_16 ( V_2 ) ;
if ( ( V_13 & V_17 ) != V_17 )
return - V_18 ;
V_4 = 0 ;
V_3 [ V_4 ++ ] = F_4 ( V_11 ) | 1 ;
V_3 [ V_4 ++ ] = V_8 ;
V_3 [ V_4 ++ ] = V_8 ;
V_13 = V_2 -> V_9 -> V_10 ( V_2 ,
& V_3 [ 0 ] , V_4 ) ;
if ( V_13 )
return V_13 ;
V_13 = V_2 -> V_9 -> V_19 ( V_2 , V_12 , 1 ) ;
if ( V_13 )
return V_13 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_13 ;
T_1 V_20 ;
F_6 ( V_2 -> V_21 , L_1 ) ;
F_6 ( V_2 -> V_21 , L_2 ) ;
V_2 -> V_9 -> V_22 ( V_2 ) ;
F_6 ( V_2 -> V_21 , L_3 ) ;
V_13 = F_1 ( V_2 ) ;
if ( V_13 )
return V_13 ;
F_6 ( V_2 -> V_21 , L_4 ) ;
V_13 = F_3 (
V_2 , V_2 -> V_5 -> V_23 , & V_20 ) ;
F_6 ( V_2 -> V_21 , L_5 , V_20 ) ;
if ( V_13 )
return V_13 ;
F_6 ( V_2 -> V_21 , L_3 ) ;
V_13 = F_1 ( V_2 ) ;
if ( V_13 )
return V_13 ;
return 0 ;
}
static T_2
F_7 ( struct V_24 * V_24 , char T_3 * V_25 , T_4 V_26 , T_5 * V_27 )
{
struct V_1 * V_2 = V_24 -> V_28 ;
T_2 V_29 = 0 ;
T_1 * V_30 ;
T_1 V_31 ;
T_1 V_32 ;
int V_13 ;
V_13 = F_8 ( & V_2 -> V_33 ) ;
if ( V_13 )
return V_13 ;
if ( V_2 -> V_34 ) {
V_29 =
( V_26 < V_2 -> V_34 ) ? V_26 :
V_2 -> V_34 ;
if ( F_9 ( V_25 , V_2 -> V_35 , V_29 ) ) {
V_13 = - V_36 ;
goto error;
}
V_2 -> V_34 -= V_29 ;
memmove ( V_2 -> V_35 ,
V_2 -> V_35 + V_29 ,
4 - V_29 ) ;
} else {
V_30 = ( T_1 * ) F_10 ( V_37 ) ;
if ( ! V_30 ) {
V_13 = - V_38 ;
goto error;
}
V_31 = ( ( V_26 + 3 ) >> 2 ) ;
V_29 = V_31 << 2 ;
if ( V_29 > V_39 )
V_29 = V_39 ;
V_32 = V_29 & 3 ;
V_29 &= ~ 3 ;
V_31 = V_29 >> 2 ;
V_13 = V_2 -> V_9 -> V_19 ( V_2 ,
V_30 , V_31 ) ;
if ( V_13 ) {
F_11 ( ( unsigned long ) V_30 ) ;
goto error;
}
if ( F_9 ( V_25 , V_30 , V_29 ) ) {
F_11 ( ( unsigned long ) V_30 ) ;
V_13 = - V_36 ;
goto error;
}
memcpy ( V_2 -> V_35 ,
V_30 ,
V_32 ) ;
V_2 -> V_34 = V_32 ;
F_11 ( ( unsigned long ) V_30 ) ;
}
V_13 = V_29 ;
error:
F_12 ( & V_2 -> V_33 ) ;
return V_13 ;
}
static T_2
F_13 ( struct V_24 * V_24 , const char T_3 * V_25 ,
T_4 V_26 , T_5 * V_27 )
{
struct V_1 * V_2 = V_24 -> V_28 ;
T_2 V_40 = 0 ;
T_2 V_41 = V_26 ;
T_1 * V_30 ;
T_2 V_42 ;
T_2 V_13 ;
V_13 = F_8 ( & V_2 -> V_33 ) ;
if ( V_13 )
return V_13 ;
V_41 += V_2 -> V_43 ;
if ( V_41 < 4 ) {
V_13 = 0 ;
goto error;
}
V_30 = ( T_1 * ) F_14 ( V_37 ) ;
if ( ! V_30 ) {
V_13 = - V_38 ;
goto error;
}
while ( V_41 > 3 ) {
V_42 = V_41 ;
if ( V_42 > V_39 )
V_42 = V_39 ;
V_42 &= ~ 3 ;
if ( V_2 -> V_43 ) {
memcpy ( V_30 , V_2 -> V_44 ,
V_2 -> V_43 ) ;
if ( F_15 (
( ( ( char * ) V_30 ) + V_2 -> V_43 ) ,
V_25 + V_40 ,
V_42 - ( V_2 -> V_43 ) ) ) {
F_11 ( ( unsigned long ) V_30 ) ;
V_13 = - V_36 ;
goto error;
}
} else {
if ( F_15 ( V_30 , V_25 + V_40 , V_42 ) ) {
F_11 ( ( unsigned long ) V_30 ) ;
V_13 = - V_36 ;
goto error;
}
}
V_13 = V_2 -> V_9 -> V_10 ( V_2 ,
V_30 , V_42 >> 2 ) ;
if ( V_13 ) {
F_11 ( ( unsigned long ) V_30 ) ;
V_13 = - V_36 ;
goto error;
}
if ( V_2 -> V_43 ) {
V_42 -= V_2 -> V_43 ;
V_41 -= V_2 -> V_43 ;
V_2 -> V_43 = 0 ;
}
V_40 += V_42 ;
V_41 -= V_42 ;
}
if ( ( V_41 > 0 ) && ( V_41 < 4 ) ) {
if ( ! F_15 ( V_2 -> V_44 ,
V_25 + V_40 , V_41 ) ) {
V_2 -> V_43 = V_41 ;
V_40 += V_41 ;
V_41 = 0 ;
}
}
F_11 ( ( unsigned long ) V_30 ) ;
V_13 = V_40 ;
error:
F_12 ( & V_2 -> V_33 ) ;
return V_13 ;
}
static int F_16 ( struct V_45 * V_45 , struct V_24 * V_24 )
{
struct V_1 * V_2 ;
int V_13 ;
F_17 ( & V_46 ) ;
V_2 = F_18 ( V_45 -> V_47 , struct V_1 , V_48 ) ;
V_13 = F_8 ( & V_2 -> V_33 ) ;
if ( V_13 )
goto V_49;
if ( V_2 -> V_50 ) {
V_13 = - V_51 ;
goto error;
}
V_13 = F_5 ( V_2 ) ;
if ( V_13 ) {
F_19 ( V_2 -> V_21 , L_6 ) ;
goto error;
}
V_24 -> V_28 = V_2 ;
V_2 -> V_43 = 0 ;
V_2 -> V_34 = 0 ;
V_2 -> V_50 = 1 ;
error:
F_12 ( & V_2 -> V_33 ) ;
V_49:
F_12 ( & V_46 ) ;
return V_13 ;
}
static int F_20 ( struct V_45 * V_45 , struct V_24 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_28 ;
int V_52 ;
int V_13 = 0 ;
F_17 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_43 ) {
for ( V_52 = V_2 -> V_43 ; V_52 < 4 ; V_52 ++ )
V_2 -> V_44 [ V_52 ] = 0 ;
V_13 = V_2 -> V_9 -> V_10 ( V_2 ,
( T_1 * ) V_2 -> V_44 , 1 ) ;
if ( V_13 )
goto error;
}
V_13 = F_1 ( V_2 ) ;
if ( V_13 )
goto error;
error:
V_2 -> V_50 = 0 ;
F_12 ( & V_2 -> V_33 ) ;
return V_13 ;
}
static int F_21 ( struct V_53 * V_21 , int V_54 ,
const struct V_55 * V_56 ,
const struct V_57 * V_9 ,
const struct V_58 * V_5 )
{
T_6 V_59 ;
struct V_1 * V_2 = NULL ;
int V_60 = 0 ;
F_22 ( V_21 , L_7 ) ;
F_17 ( & V_61 ) ;
if ( V_54 < 0 ) {
for ( V_54 = 0 ; V_54 < V_62 ; V_54 ++ )
if ( ! V_63 [ V_54 ] )
break;
}
if ( V_54 < 0 || V_54 >= V_62 ) {
F_12 ( & V_61 ) ;
F_19 ( V_21 , L_8 , V_64 , V_54 ) ;
return - V_65 ;
}
if ( V_63 [ V_54 ] ) {
F_12 ( & V_61 ) ;
F_19 ( V_21 , L_9 ,
V_64 , V_54 ) ;
return - V_51 ;
}
V_63 [ V_54 ] = 1 ;
F_12 ( & V_61 ) ;
V_59 = F_23 ( V_66 , V_67 + V_54 ) ;
V_2 = F_24 ( sizeof( struct V_1 ) , V_37 ) ;
if ( ! V_2 ) {
F_19 ( V_21 , L_10 ) ;
V_60 = - V_38 ;
goto V_68;
}
F_25 ( V_21 , ( void * ) V_2 ) ;
if ( ! V_56 ) {
F_19 ( V_21 , L_11 ) ;
V_60 = - V_36 ;
goto V_69;
}
V_2 -> V_70 = V_56 -> V_71 ;
V_2 -> V_72 = V_56 -> V_73 ;
V_2 -> V_74 = F_26 ( V_56 ) ;
if ( ! F_27 ( V_2 -> V_70 ,
V_2 -> V_74 , V_64 ) ) {
F_19 ( V_21 , L_12 ,
( unsigned long long ) V_56 -> V_71 ) ;
V_60 = - V_51 ;
goto V_69;
}
V_2 -> V_59 = V_59 ;
V_2 -> V_21 = V_21 ;
V_2 -> V_75 = F_28 ( V_2 -> V_70 , V_2 -> V_74 ) ;
if ( ! V_2 -> V_75 ) {
F_19 ( V_21 , L_13 ) ;
goto V_76;
}
V_2 -> V_9 = V_9 ;
V_2 -> V_5 = V_5 ;
F_29 ( & V_2 -> V_33 ) ;
V_2 -> V_50 = 0 ;
F_22 ( V_21 , L_14 ,
( unsigned long long ) V_2 -> V_70 ,
V_2 -> V_75 ,
( unsigned long long ) V_2 -> V_74 ) ;
F_30 ( & V_2 -> V_48 , & V_77 ) ;
V_2 -> V_48 . V_78 = V_79 ;
V_60 = F_31 ( & V_2 -> V_48 , V_59 , 1 ) ;
if ( V_60 ) {
F_19 ( V_21 , L_15 ) ;
goto V_80;
}
F_32 ( V_81 , V_21 , V_59 , NULL , L_16 , V_64 , V_54 ) ;
return 0 ;
V_80:
F_33 ( V_2 -> V_75 ) ;
V_76:
F_34 ( V_56 -> V_71 , V_2 -> V_74 ) ;
V_69:
F_35 ( V_2 ) ;
V_68:
F_17 ( & V_61 ) ;
V_63 [ V_54 ] = 0 ;
F_12 ( & V_61 ) ;
return V_60 ;
}
static int F_36 ( struct V_53 * V_21 )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) F_37 ( V_21 ) ;
if ( ! V_2 )
return 0 ;
F_38 ( V_81 , V_2 -> V_59 ) ;
F_39 ( & V_2 -> V_48 ) ;
F_33 ( V_2 -> V_75 ) ;
F_34 ( V_2 -> V_70 , V_2 -> V_74 ) ;
F_35 ( V_2 ) ;
F_25 ( V_21 , NULL ) ;
F_17 ( & V_61 ) ;
V_63 [ F_40 ( V_21 -> V_59 ) - V_67 ] = 0 ;
F_12 ( & V_61 ) ;
return 0 ;
}
static int F_41 ( struct V_82 * V_83 ,
const struct V_57 * V_9 )
{
struct V_55 V_84 ;
const unsigned int * V_54 ;
const char * V_85 ;
int V_86 ;
const struct V_58 * V_87 ;
V_86 = F_42 ( V_83 -> V_21 . V_88 , 0 , & V_84 ) ;
if ( V_86 ) {
F_19 ( & V_83 -> V_21 , L_17 ) ;
return V_86 ;
}
V_54 = F_43 ( V_83 -> V_21 . V_88 , L_18 , NULL ) ;
V_87 = & V_89 ;
V_85 = F_43 ( V_83 -> V_21 . V_88 , L_19 , NULL ) ;
if ( V_85 ) {
if ( ! strcmp ( V_85 , L_20 ) ) {
V_87 = & V_90 ;
} else if ( ! strcmp ( V_85 , L_21 ) ) {
V_87 = & V_89 ;
} else if ( ! strcmp ( V_85 , L_22 ) ) {
V_87 = & V_91 ;
} else if ( ! strcmp ( V_85 , L_23 ) ) {
V_87 = & V_92 ;
}
}
return F_21 ( & V_83 -> V_21 , V_54 ? * V_54 : - 1 , & V_84 , V_9 ,
V_87 ) ;
}
static inline int F_41 ( struct V_82 * V_83 ,
const struct V_57 * V_9 )
{
return - V_65 ;
}
static int F_44 ( struct V_82 * V_93 )
{
const struct V_94 * V_95 ;
struct V_55 * V_84 ;
const struct V_58 * V_87 ;
const char * V_85 ;
V_95 = F_45 ( V_96 , & V_93 -> V_21 ) ;
if ( V_95 )
return F_41 ( V_93 , V_95 -> V_97 ) ;
V_84 = F_46 ( V_93 , V_98 , 0 ) ;
if ( ! V_84 )
return - V_99 ;
V_87 = & V_89 ;
V_85 = V_93 -> V_21 . V_100 ;
if ( V_85 ) {
if ( ! strcmp ( V_85 , L_20 ) ) {
V_87 = & V_90 ;
} else if ( ! strcmp ( V_85 , L_21 ) ) {
V_87 = & V_89 ;
} else if ( ! strcmp ( V_85 , L_22 ) ) {
V_87 = & V_91 ;
} else if ( ! strcmp ( V_85 , L_23 ) ) {
V_87 = & V_92 ;
}
}
return F_21 ( & V_93 -> V_21 , V_93 -> V_54 , V_84 ,
& V_101 , V_87 ) ;
}
static int F_47 ( struct V_82 * V_93 )
{
return F_36 ( & V_93 -> V_21 ) ;
}
static int T_7 F_48 ( void )
{
T_6 V_59 ;
int V_60 ;
V_81 = F_49 ( V_79 , L_24 ) ;
F_29 ( & V_61 ) ;
V_59 = F_23 ( V_66 , V_67 ) ;
V_60 = F_50 ( V_59 ,
V_62 ,
V_64 ) ;
if ( V_60 < 0 )
return V_60 ;
V_60 = F_51 ( & V_102 ) ;
if ( V_60 )
goto V_103;
return V_60 ;
V_103:
F_52 ( V_59 , V_62 ) ;
return V_60 ;
}
static void T_8 F_53 ( void )
{
T_6 V_59 = F_23 ( V_66 , V_67 ) ;
F_54 ( V_81 ) ;
F_55 ( & V_102 ) ;
F_52 ( V_59 , V_62 ) ;
}
