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
if ( V_7 -> V_10 > 1600 || V_7 -> V_11 > 1200 )
return - V_12 ;
if ( ( V_7 -> V_10 > 1280 || V_7 -> V_11 > 1024 ) && V_7 -> V_13 > 16 )
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
if ( F_5 ( V_7 -> V_10 , V_7 -> V_13 ) * V_7 -> V_11 > V_9 -> V_20 . V_21 )
return - V_12 ;
return 0 ;
}
static int F_6 ( struct V_8 * V_9 )
{
if ( V_9 -> V_7 . V_13 > 8 )
V_9 -> V_20 . V_22 = V_23 ;
else
V_9 -> V_20 . V_22 = V_24 ;
V_9 -> V_20 . V_25 = F_5 ( V_9 -> V_7 . V_10 , V_9 -> V_7 . V_13 ) ;
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
if ( V_39 < 0 )
return V_39 ;
V_39 = F_15 ( V_36 , 3 , L_1 ) ;
if ( V_39 < 0 )
return V_39 ;
V_38 -> V_40 = F_16 ( V_36 , 3 ) ;
if ( ! V_38 -> V_40 )
return - V_41 ;
V_39 = F_15 ( V_36 , 2 , L_2 ) ;
if ( V_39 < 0 )
return V_39 ;
V_38 -> V_42 = F_16 ( V_36 , 2 ) ;
if ( ! V_38 -> V_42 )
return - V_41 ;
V_39 = F_15 ( V_36 , 1 , L_3 ) ;
if ( V_39 < 0 )
return V_39 ;
V_38 -> V_43 = F_16 ( V_36 , 1 ) ;
if ( ! V_38 -> V_43 )
return - V_41 ;
V_39 = F_15 ( V_36 , 0 , L_4 ) ;
if ( V_39 < 0 )
return V_39 ;
V_9 -> V_20 . V_44 = F_17 ( V_36 , 0 ) ;
V_9 -> V_20 . V_21 = V_45 ? V_45 : F_18 () ;
V_9 -> V_46 = F_19 ( V_9 -> V_20 . V_44 , V_9 -> V_20 . V_21 ) ;
if ( ! V_9 -> V_46 )
return - V_41 ;
F_20 ( V_38 , V_47 , V_9 -> V_20 . V_44 & 0xFF000000 ) ;
F_21 ( & V_36 -> V_36 , L_5 ,
V_9 -> V_20 . V_21 / 1024 , V_9 -> V_20 . V_44 ) ;
return 0 ;
}
static struct V_8 * F_22 ( struct V_48 * V_36 )
{
struct V_37 * V_38 ;
struct V_8 * V_9 ;
V_9 = F_23 ( sizeof( struct V_37 ) + sizeof( T_2 ) * 16 ,
V_36 ) ;
if ( ! V_9 )
return NULL ;
V_38 = V_9 -> V_38 ;
strcpy ( V_9 -> V_20 . V_49 , L_6 ) ;
V_9 -> V_20 . type = V_50 ;
V_9 -> V_20 . V_51 = 0 ;
V_9 -> V_20 . V_52 = 0 ;
V_9 -> V_20 . V_53 = 0 ;
V_9 -> V_20 . V_54 = 0 ;
V_9 -> V_20 . V_55 = V_56 ;
V_9 -> V_7 . V_57 = 0 ;
V_9 -> V_7 . V_58 = V_59 ;
V_9 -> V_7 . V_60 = - 1 ;
V_9 -> V_7 . V_61 = - 1 ;
V_9 -> V_7 . V_62 = 0 ;
V_9 -> V_7 . V_63 = V_64 ;
V_9 -> V_65 = & V_66 ;
V_9 -> V_67 = V_68 ;
V_9 -> V_69 = - 1 ;
V_9 -> V_32 = ( void * ) V_38 + sizeof( struct V_37 ) ;
V_9 -> V_7 . V_30 = 0 ;
if ( F_24 ( & V_9 -> V_70 , 256 , 0 ) < 0 ) {
F_25 ( V_9 ) ;
return NULL ;
}
return V_9 ;
}
static int F_26 ( struct V_35 * V_71 , T_3 V_72 )
{
struct V_8 * V_9 = F_27 ( V_71 ) ;
if ( V_72 . V_73 == V_74 ) {
F_28 () ;
F_29 ( V_9 ) ;
F_30 ( V_9 , 1 ) ;
F_31 () ;
}
return 0 ;
}
static int F_32 ( struct V_35 * V_71 )
{
struct V_8 * V_9 = F_27 ( V_71 ) ;
int V_39 ;
F_28 () ;
V_39 = F_33 ( V_9 ) ;
if ( V_39 ) {
F_34 ( V_75 L_7 ) ;
return V_39 ;
}
F_30 ( V_9 , 0 ) ;
F_31 () ;
return 0 ;
}
static int F_35 ( struct V_35 * V_71 , const struct V_76 * V_49 )
{
struct V_37 * V_38 ;
struct V_8 * V_9 ;
int V_39 ;
unsigned long V_77 ;
struct V_1 * V_78 ;
unsigned int V_79 ;
V_9 = F_22 ( & V_71 -> V_36 ) ;
if ( ! V_9 )
return - V_41 ;
V_38 = V_9 -> V_38 ;
if ( ( V_39 = F_13 ( V_9 , V_71 ) ) < 0 ) {
F_36 ( & V_71 -> V_36 , L_8 ) ;
goto V_80;
}
F_37 ( V_81 , V_77 ) ;
if ( ( V_77 & V_82 ) == V_82 )
V_38 -> V_83 = 0 ;
else
V_38 -> V_83 = 1 ;
F_1 ( & V_78 , & V_79 ) ;
V_39 = F_38 ( & V_9 -> V_7 , V_9 , V_84 ,
V_78 , V_79 , NULL , 16 ) ;
if ( V_39 == 0 || V_39 == 4 ) {
F_36 ( & V_71 -> V_36 , L_9 ) ;
V_39 = - V_12 ;
goto V_80;
}
F_39 ( V_9 -> V_46 , 0 , V_9 -> V_20 . V_21 ) ;
F_4 ( & V_9 -> V_7 , V_9 ) ;
F_6 ( V_9 ) ;
F_40 ( V_85 ) ;
if ( F_41 ( V_9 ) < 0 ) {
V_39 = - V_12 ;
goto V_80;
}
F_42 ( V_71 , V_9 ) ;
V_8 ( V_9 , L_10 , V_9 -> V_20 . V_49 ) ;
return 0 ;
V_80:
if ( V_9 -> V_46 ) {
F_43 ( V_9 -> V_46 ) ;
F_44 ( V_71 , 0 ) ;
}
if ( V_38 -> V_40 ) {
F_43 ( V_38 -> V_40 ) ;
F_44 ( V_71 , 3 ) ;
}
if ( V_38 -> V_42 ) {
F_43 ( V_38 -> V_42 ) ;
F_44 ( V_71 , 2 ) ;
}
if ( V_38 -> V_43 ) {
F_43 ( V_38 -> V_43 ) ;
F_44 ( V_71 , 1 ) ;
}
if ( V_9 ) {
F_45 ( & V_9 -> V_70 ) ;
F_25 ( V_9 ) ;
}
return V_39 ;
}
static void F_46 ( struct V_35 * V_71 )
{
struct V_8 * V_9 = F_27 ( V_71 ) ;
struct V_37 * V_38 = V_9 -> V_38 ;
F_47 ( V_9 ) ;
F_43 ( ( void V_86 * ) V_9 -> V_46 ) ;
F_44 ( V_71 , 0 ) ;
F_43 ( V_38 -> V_40 ) ;
F_44 ( V_71 , 3 ) ;
F_43 ( V_38 -> V_42 ) ;
F_44 ( V_71 , 2 ) ;
F_43 ( V_38 -> V_43 ) ;
F_44 ( V_71 , 1 ) ;
F_45 ( & V_9 -> V_70 ) ;
F_25 ( V_9 ) ;
}
static int T_4 F_48 ( char * V_87 )
{
char * V_88 ;
if ( ! V_87 || ! * V_87 )
return 0 ;
while ( ( V_88 = F_49 ( & V_87 , L_11 ) ) != NULL ) {
if ( ! * V_88 )
continue;
V_84 = V_88 ;
}
return 0 ;
}
static int T_4 F_50 ( void )
{
#ifndef F_51
char * V_89 = NULL ;
if ( F_52 ( L_12 , & V_89 ) )
return - V_90 ;
F_48 ( V_89 ) ;
#endif
return F_53 ( & V_91 ) ;
}
static void T_5 F_54 ( void )
{
F_55 ( & V_91 ) ;
}
