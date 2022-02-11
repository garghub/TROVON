static void F_1 ( struct V_1 * * V_2 , unsigned int * V_3 )
{
if ( F_2 () ) {
* V_2 = (struct V_1 * ) V_4 ;
* V_3 = F_3 ( V_4 ) ;
} else {
* V_2 = (struct V_1 * ) V_5 ;
* V_3 = F_3 ( V_5 ) ;
}
}
static void F_1 ( struct V_1 * * V_2 , unsigned int * V_3 )
{
* V_2 = (struct V_1 * ) V_5 ;
* V_3 = F_3 ( V_5 ) ;
}
static int F_4 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
if ( V_7 -> V_10 > 1920 || V_7 -> V_11 > 1440 )
return - V_12 ;
if ( V_7 -> V_13 == 32 ) {
V_7 -> V_14 . V_15 = 16 ; V_7 -> V_14 . V_16 = 8 ;
V_7 -> V_17 . V_15 = 8 ; V_7 -> V_17 . V_16 = 8 ;
V_7 -> V_18 . V_15 = 0 ; V_7 -> V_18 . V_16 = 8 ;
} else if ( V_7 -> V_13 == 16 ) {
V_7 -> V_14 . V_15 = 11 ; V_7 -> V_14 . V_16 = 5 ;
V_7 -> V_17 . V_15 = 5 ; V_7 -> V_17 . V_16 = 6 ;
V_7 -> V_18 . V_15 = 0 ; V_7 -> V_18 . V_16 = 5 ;
} else if ( V_7 -> V_13 == 8 ) {
V_7 -> V_14 . V_15 = 0 ; V_7 -> V_14 . V_16 = 8 ;
V_7 -> V_17 . V_15 = 0 ; V_7 -> V_17 . V_16 = 8 ;
V_7 -> V_18 . V_15 = 0 ; V_7 -> V_18 . V_16 = 8 ;
} else
return - V_12 ;
V_7 -> V_19 . V_15 = 0 ; V_7 -> V_19 . V_16 = 0 ;
if ( ( F_5 ( V_7 -> V_10 , V_7 -> V_13 ) * V_7 -> V_11 )
> V_9 -> V_20 . V_21 )
return - V_12 ;
return 0 ;
}
static int F_6 ( struct V_8 * V_9 )
{
if ( V_9 -> V_7 . V_13 > 8 )
V_9 -> V_20 . V_22 = V_23 ;
else
V_9 -> V_20 . V_22 = V_24 ;
V_9 -> V_20 . V_25 = F_5 ( V_9 -> V_7 . V_10 ,
V_9 -> V_7 . V_13 ) ;
F_7 ( V_9 ) ;
return 0 ;
}
static inline T_1 F_8 ( T_1 V_26 , struct V_27 * V_28 )
{
V_26 &= 0xffff ;
V_26 >>= 16 - V_28 -> V_16 ;
return V_26 << V_28 -> V_15 ;
}
static int F_9 ( unsigned V_29 , unsigned V_14 , unsigned V_17 ,
unsigned V_18 , unsigned V_19 ,
struct V_8 * V_9 )
{
if ( V_9 -> V_7 . V_30 ) {
V_14 = V_17 = V_18 = ( V_14 * 77 + V_17 * 151 + V_18 * 28 ) >> 8 ;
}
if ( V_9 -> V_20 . V_22 == V_23 ) {
T_2 * V_31 = V_9 -> V_32 ;
T_2 V_33 ;
if ( V_29 >= 16 )
return - V_12 ;
V_33 = F_8 ( V_14 , & V_9 -> V_7 . V_14 ) ;
V_33 |= F_8 ( V_17 , & V_9 -> V_7 . V_17 ) ;
V_33 |= F_8 ( V_18 , & V_9 -> V_7 . V_18 ) ;
V_31 [ V_29 ] = V_33 ;
} else {
if ( V_29 >= 256 )
return - V_12 ;
F_10 ( V_9 , V_29 , V_14 , V_17 , V_18 ) ;
}
return 0 ;
}
static int F_11 ( int V_34 , struct V_8 * V_9 )
{
return F_12 ( V_9 , V_34 ) ;
}
static int F_13 ( struct V_8 * V_9 , struct V_35 * V_36 )
{
struct V_37 * V_38 = V_9 -> V_38 ;
int V_39 ;
V_39 = F_14 ( V_36 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_15 ( V_36 , 0 , L_1 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_15 ( V_36 , 1 , L_2 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_15 ( V_36 , 2 , L_3 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_15 ( V_36 , 3 , L_4 ) ;
if ( V_39 )
return V_39 ;
V_9 -> V_20 . V_40 = F_16 ( V_36 , 0 ) ;
V_9 -> V_20 . V_21 = V_41 ? V_41 : F_17 () ;
V_9 -> V_42 = F_18 ( V_9 -> V_20 . V_40 , V_9 -> V_20 . V_21 ) ;
V_39 = - V_43 ;
if ( V_9 -> V_42 == NULL )
return V_39 ;
V_38 -> V_44 = F_19 ( V_36 , 1 ) ;
if ( V_38 -> V_44 == NULL )
return V_39 ;
V_38 -> V_45 = F_19 ( V_36 , 2 ) ;
if ( V_38 -> V_45 == NULL )
return V_39 ;
V_38 -> V_46 = F_19 ( V_36 , 3 ) ;
if ( V_38 -> V_46 == NULL )
return V_39 ;
F_20 ( V_38 , V_47 , V_48 ) ;
F_20 ( V_38 , V_49 , V_9 -> V_20 . V_40 & 0xFF000000 ) ;
F_20 ( V_38 , V_47 , V_50 ) ;
F_21 ( & V_36 -> V_36 , L_5 ,
V_9 -> V_20 . V_21 / 1024 , V_9 -> V_20 . V_40 ) ;
return 0 ;
}
static struct V_8 * F_22 ( struct V_51 * V_36 )
{
struct V_37 * V_38 ;
struct V_8 * V_9 ;
V_9 = F_23 ( sizeof( struct V_37 ) + sizeof( T_2 ) * 16 ,
V_36 ) ;
if ( ! V_9 )
return NULL ;
V_38 = V_9 -> V_38 ;
strcpy ( V_9 -> V_20 . V_52 , L_6 ) ;
V_9 -> V_20 . type = V_53 ;
V_9 -> V_20 . V_54 = 0 ;
V_9 -> V_20 . V_55 = 0 ;
V_9 -> V_20 . V_56 = 0 ;
V_9 -> V_20 . V_57 = 0 ;
V_9 -> V_20 . V_58 = V_59 ;
V_9 -> V_7 . V_60 = 0 ;
V_9 -> V_7 . V_61 = V_62 ;
V_9 -> V_7 . V_63 = - 1 ;
V_9 -> V_7 . V_64 = - 1 ;
V_9 -> V_7 . V_65 = 0 ;
V_9 -> V_7 . V_66 = V_67 ;
V_9 -> V_68 = & V_69 ;
V_9 -> V_70 = V_71 ;
V_9 -> V_72 = - 1 ;
V_9 -> V_32 = ( void * ) V_38 + sizeof( struct V_37 ) ;
if ( F_24 ( & V_9 -> V_73 , 256 , 0 ) < 0 ) {
F_25 ( V_9 ) ;
return NULL ;
}
V_9 -> V_7 . V_30 = 0 ;
return V_9 ;
}
static int F_26 ( struct V_35 * V_74 , T_3 V_75 )
{
struct V_8 * V_9 = F_27 ( V_74 ) ;
if ( V_75 . V_76 == V_77 ) {
F_28 () ;
F_29 ( V_9 ) ;
F_30 ( V_9 , 1 ) ;
F_31 () ;
}
return 0 ;
}
static int F_32 ( struct V_35 * V_74 )
{
struct V_8 * V_9 = F_27 ( V_74 ) ;
int V_39 ;
F_28 () ;
V_39 = F_33 ( V_9 ) ;
if ( V_39 ) {
F_34 ( V_78 L_7 ) ;
return V_39 ;
}
F_30 ( V_9 , 0 ) ;
F_31 () ;
return 0 ;
}
static int F_35 ( struct V_35 * V_74 , const struct V_79 * V_52 )
{
struct V_37 * V_38 ;
struct V_8 * V_9 ;
int V_39 ;
struct V_1 * V_80 ;
unsigned int V_81 ;
V_9 = F_22 ( & V_74 -> V_36 ) ;
if ( V_9 == NULL )
return - V_43 ;
V_38 = V_9 -> V_38 ;
V_39 = F_13 ( V_9 , V_74 ) ;
if ( V_39 < 0 ) {
F_36 ( & V_74 -> V_36 ,
L_8 ) ;
goto V_82;
}
V_38 -> V_83 = 0 ;
V_38 -> V_83 |= ( V_84 ) ? 0 : V_85 ;
V_38 -> V_83 |= ( V_86 ) ? 0 : V_87 ;
F_1 ( & V_80 , & V_81 ) ;
V_39 = F_37 ( & V_9 -> V_7 , V_9 , V_88 ,
V_80 , V_81 , NULL , 16 ) ;
if ( V_39 == 0 || V_39 == 4 ) {
F_36 ( & V_74 -> V_36 , L_9 ) ;
V_39 = - V_12 ;
goto V_82;
}
if ( ! V_89 )
F_38 ( V_9 -> V_42 , 0 , V_9 -> V_20 . V_21 ) ;
F_4 ( & V_9 -> V_7 , V_9 ) ;
F_6 ( V_9 ) ;
F_39 ( V_90 ) ;
if ( F_40 ( V_9 ) < 0 ) {
V_39 = - V_12 ;
goto V_82;
}
F_41 ( V_74 , V_9 ) ;
V_8 ( V_9 , L_10 , V_9 -> V_20 . V_52 ) ;
return 0 ;
V_82:
if ( V_9 -> V_42 ) {
F_42 ( V_9 -> V_42 ) ;
F_43 ( V_74 , 0 ) ;
}
if ( V_38 -> V_44 ) {
F_42 ( V_38 -> V_44 ) ;
F_43 ( V_74 , 1 ) ;
}
if ( V_38 -> V_45 ) {
F_42 ( V_38 -> V_45 ) ;
F_43 ( V_74 , 2 ) ;
}
if ( V_38 -> V_46 ) {
F_42 ( V_38 -> V_46 ) ;
F_43 ( V_74 , 3 ) ;
}
F_44 ( & V_9 -> V_73 ) ;
F_25 ( V_9 ) ;
return V_39 ;
}
static void F_45 ( struct V_35 * V_74 )
{
struct V_8 * V_9 = F_27 ( V_74 ) ;
struct V_37 * V_38 = V_9 -> V_38 ;
F_46 ( V_9 ) ;
F_42 ( V_9 -> V_42 ) ;
F_43 ( V_74 , 0 ) ;
F_42 ( V_38 -> V_44 ) ;
F_43 ( V_74 , 1 ) ;
F_42 ( V_38 -> V_45 ) ;
F_43 ( V_74 , 2 ) ;
F_42 ( V_38 -> V_46 ) ;
F_43 ( V_74 , 3 ) ;
F_44 ( & V_9 -> V_73 ) ;
F_25 ( V_9 ) ;
}
static int T_4 F_47 ( char * V_91 )
{
char * V_92 ;
if ( ! V_91 || ! * V_91 )
return 0 ;
while ( ( V_92 = F_48 ( & V_91 , L_11 ) ) != NULL ) {
if ( ! * V_92 )
continue;
if ( ! strcmp ( V_92 , L_12 ) )
V_89 = 1 ;
else if ( ! strcmp ( V_92 , L_13 ) )
V_84 = 1 ;
else if ( ! strcmp ( V_92 , L_14 ) )
V_86 = 1 ;
else
V_88 = V_92 ;
}
return 0 ;
}
static int T_4 F_49 ( void )
{
#ifndef F_50
char * V_93 = NULL ;
if ( F_51 ( L_15 , & V_93 ) )
return - V_94 ;
F_47 ( V_93 ) ;
#endif
return F_52 ( & V_95 ) ;
}
static void T_5 F_53 ( void )
{
F_54 ( & V_95 ) ;
}
