static int F_1 ( int V_1 , int V_2 )
{
int V_3 = V_1 * ( V_2 >> 3 ) ;
if ( V_3 > 2048 )
V_3 = 4096 ;
else if ( V_3 > 1024 )
V_3 = 2048 ;
else
V_3 = 1024 ;
return V_3 ;
}
static int F_2 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
if ( V_5 -> V_1 > 1280 || V_5 -> V_10 > 1024 )
return - V_11 ;
if ( V_9 -> V_12 && ( V_5 -> V_1 > V_9 -> V_12 || V_5 -> V_10 > V_9 -> V_13 ) )
return - V_11 ;
if ( V_5 -> V_14 == 16 ) {
V_5 -> V_15 . V_16 = 11 ; V_5 -> V_15 . V_17 = 5 ;
V_5 -> V_18 . V_16 = 5 ; V_5 -> V_18 . V_17 = 6 ;
V_5 -> V_19 . V_16 = 0 ; V_5 -> V_19 . V_17 = 5 ;
V_5 -> V_20 . V_16 = 0 ; V_5 -> V_20 . V_17 = 0 ;
} else if ( V_5 -> V_14 == 8 ) {
V_5 -> V_15 . V_16 = 0 ; V_5 -> V_15 . V_17 = 8 ;
V_5 -> V_18 . V_16 = 0 ; V_5 -> V_18 . V_17 = 8 ;
V_5 -> V_19 . V_16 = 0 ; V_5 -> V_19 . V_17 = 8 ;
V_5 -> V_20 . V_16 = 0 ; V_5 -> V_20 . V_17 = 0 ;
} else
return - V_11 ;
if ( F_1 ( V_5 -> V_1 , V_5 -> V_14 ) * V_5 -> V_10 > V_7 -> V_21 . V_22 )
return - V_11 ;
return 0 ;
}
static int F_3 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
if ( V_7 -> V_5 . V_14 == 16 )
V_7 -> V_21 . V_23 = V_24 ;
else
V_7 -> V_21 . V_23 = V_25 ;
V_7 -> V_21 . V_26 = F_1 ( V_7 -> V_5 . V_1 , V_7 -> V_5 . V_14 ) ;
V_9 -> V_27 -> V_28 ( V_7 ) ;
return 0 ;
}
static inline T_1 F_4 ( T_1 V_29 , struct V_30 * V_31 )
{
V_29 &= 0xffff ;
V_29 >>= 16 - V_31 -> V_17 ;
return V_29 << V_31 -> V_16 ;
}
static int F_5 ( unsigned V_32 , unsigned V_15 , unsigned V_18 ,
unsigned V_19 , unsigned V_20 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
if ( V_7 -> V_5 . V_33 ) {
V_15 = V_18 = V_19 = ( V_15 * 77 + V_18 * 151 + V_19 * 28 ) >> 8 ;
}
if ( V_7 -> V_21 . V_23 == V_24 ) {
T_2 * V_34 = V_7 -> V_35 ;
T_2 V_36 ;
if ( V_32 >= 16 )
return - V_11 ;
V_36 = F_4 ( V_15 , & V_7 -> V_5 . V_15 ) ;
V_36 |= F_4 ( V_18 , & V_7 -> V_5 . V_18 ) ;
V_36 |= F_4 ( V_19 , & V_7 -> V_5 . V_19 ) ;
V_34 [ V_32 ] = V_36 ;
} else {
if ( V_32 >= 256 )
return - V_11 ;
V_9 -> V_27 -> V_37 ( V_7 , V_32 , V_15 , V_18 , V_19 ) ;
}
return 0 ;
}
static int F_6 ( int V_38 , struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
return V_9 -> V_39 -> V_40 ( V_7 , V_38 ) ;
}
static int F_7 ( struct V_6 * V_7 , struct V_41 * V_42 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
unsigned V_43 ;
int V_44 ;
int V_45 ;
V_43 = F_8 () ;
if ( ! V_43 )
return - V_46 ;
V_45 = F_9 ( V_42 ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 = F_10 ( V_42 , 0 , L_1 ) ;
if ( V_45 < 0 )
return V_45 ;
V_9 -> V_47 = F_11 ( V_42 , 0 ) ;
if ( ! V_9 -> V_47 )
return - V_48 ;
if ( ! F_12 ( V_43 + 0x8300 , 0x100 , L_2 ) )
return - V_49 ;
V_9 -> V_50 = F_13 ( V_43 + 0x8300 , 0x100 ) ;
if ( ! V_9 -> V_50 )
return - V_48 ;
if ( ( V_44 = F_14 () ) < 0 )
return - V_48 ;
V_7 -> V_21 . V_51 = V_43 + 0x800000 ;
V_7 -> V_21 . V_22 = V_44 ;
V_7 -> V_52 = F_13 ( V_7 -> V_21 . V_51 , V_7 -> V_21 . V_22 ) ;
if ( ! V_7 -> V_52 )
return - V_48 ;
F_15 ( & V_42 -> V_42 , L_3 ,
V_7 -> V_21 . V_22 / 1024 , V_7 -> V_21 . V_51 ) ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
if ( strcmp ( V_53 , L_4 ) != 0 ) {
int V_54 , V_55 ;
char * V_56 ;
V_54 = F_17 ( V_53 , & V_56 , 10 ) ;
if ( ! V_54 )
return - V_11 ;
V_55 = F_17 ( V_56 + 1 , NULL , 10 ) ;
if ( ! V_55 )
return - V_11 ;
V_9 -> V_12 = V_54 ;
V_9 -> V_13 = V_55 ;
}
return 0 ;
}
static struct V_6 * F_18 ( struct V_57 * V_42 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
V_7 = F_19 ( sizeof( struct V_8 ) + sizeof( T_2 ) * 16 , V_42 ) ;
if ( ! V_7 )
return NULL ;
V_9 = V_7 -> V_9 ;
strcpy ( V_7 -> V_21 . V_58 , L_5 ) ;
V_7 -> V_21 . type = V_59 ;
V_7 -> V_21 . V_60 = 0 ;
V_7 -> V_21 . V_61 = 0 ;
V_7 -> V_21 . V_62 = 0 ;
V_7 -> V_21 . V_63 = 0 ;
V_7 -> V_21 . V_64 = V_65 ;
V_7 -> V_5 . V_66 = 0 ;
V_7 -> V_5 . V_67 = V_68 ;
V_7 -> V_5 . V_69 = - 1 ;
V_7 -> V_5 . V_70 = - 1 ;
V_7 -> V_5 . V_71 = 0 ;
V_7 -> V_5 . V_72 = V_73 ;
V_7 -> V_74 = & V_75 ;
V_7 -> V_76 = V_77 ;
V_7 -> V_78 = - 1 ;
V_7 -> V_35 = ( void * ) V_9 + sizeof( struct V_8 ) ;
V_7 -> V_5 . V_33 = 0 ;
V_9 -> V_79 = V_80 ;
if ( F_16 ( V_7 ) < 0 )
F_20 ( V_81 L_6 ) ;
if ( ! V_9 -> V_12 )
V_9 -> V_79 = 1 ;
if ( F_21 ( & V_7 -> V_82 , 256 , 0 ) < 0 ) {
F_22 ( V_7 ) ;
return NULL ;
}
return V_7 ;
}
static int F_23 ( struct V_41 * V_83 , const struct V_84 * V_58 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
int V_45 ;
V_7 = F_18 ( & V_83 -> V_42 ) ;
if ( ! V_7 )
return - V_48 ;
V_9 = V_7 -> V_9 ;
V_9 -> V_27 = & V_85 ;
V_9 -> V_39 = & V_86 ;
if ( ( V_45 = F_7 ( V_7 , V_83 ) ) < 0 ) {
F_24 ( & V_83 -> V_42 , L_7 ) ;
goto V_87;
}
V_45 = F_25 ( & V_7 -> V_5 , V_7 , V_88 ,
V_89 , F_26 ( V_89 ) , NULL , 16 ) ;
if ( V_45 == 0 || V_45 == 4 ) {
F_24 ( & V_83 -> V_42 , L_8 ) ;
V_45 = - V_11 ;
goto V_87;
}
F_27 ( V_7 -> V_52 , 0 , V_7 -> V_21 . V_22 ) ;
F_2 ( & V_7 -> V_5 , V_7 ) ;
F_3 ( V_7 ) ;
if ( F_28 ( V_7 ) < 0 ) {
V_45 = - V_11 ;
goto V_87;
}
F_29 ( V_83 , V_7 ) ;
F_20 ( V_90 L_9 , V_7 -> V_78 , V_7 -> V_21 . V_58 ) ;
return 0 ;
V_87:
if ( V_7 -> V_52 ) {
F_30 ( V_7 -> V_52 ) ;
F_31 ( V_83 , 0 ) ;
}
if ( V_9 -> V_47 ) {
F_30 ( V_9 -> V_47 ) ;
F_31 ( V_83 , 1 ) ;
}
if ( V_9 -> V_50 ) {
F_30 ( V_9 -> V_50 ) ;
F_32 ( F_8 () + 0x8300 , 0x100 ) ;
}
if ( V_7 ) {
F_33 ( & V_7 -> V_82 ) ;
F_22 ( V_7 ) ;
}
return V_45 ;
}
static void F_34 ( struct V_41 * V_83 )
{
struct V_6 * V_7 = F_35 ( V_83 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
F_36 ( V_7 ) ;
F_30 ( ( void V_91 * ) V_7 -> V_52 ) ;
F_31 ( V_83 , 0 ) ;
F_30 ( V_9 -> V_47 ) ;
F_31 ( V_83 , 1 ) ;
F_30 ( V_9 -> V_50 ) ;
F_32 ( F_8 () + 0x8300 , 0x100 ) ;
F_33 ( & V_7 -> V_82 ) ;
F_29 ( V_83 , NULL ) ;
F_22 ( V_7 ) ;
}
static void T_3 F_37 ( char * V_92 )
{
char * V_93 ;
if ( ! V_92 || ! * V_92 )
return;
while ( ( V_93 = F_38 ( & V_92 , L_10 ) ) ) {
if ( ! * V_93 )
continue;
if ( ! strncmp ( V_93 , L_11 , 5 ) )
F_39 ( V_88 , V_93 + 5 , sizeof( V_88 ) ) ;
else if ( ! strncmp ( V_93 , L_12 , 4 ) )
V_80 = ! ! F_40 ( V_93 + 4 , NULL , 0 ) ;
else if ( ! strncmp ( V_93 , L_13 , 6 ) )
F_39 ( V_53 , V_93 + 6 , sizeof( V_53 ) ) ;
else
F_39 ( V_88 , V_93 , sizeof( V_88 ) ) ;
}
}
static int T_3 F_41 ( void )
{
#ifndef F_42
char * V_94 = NULL ;
if ( F_43 ( L_14 , & V_94 ) )
return - V_46 ;
F_37 ( V_94 ) ;
#endif
return F_44 ( & V_95 ) ;
}
static void F_45 ( void )
{
F_46 ( & V_95 ) ;
}
