static int F_1 ( void * V_1 , const void * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_1 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
T_2 * V_8 = ( T_2 * ) V_2 ;
T_2 V_9 = V_8 [ 1 ] ;
void T_3 * V_10 = ( void * ) V_8 [ 0 ] ;
F_3 ( V_9 , V_10 ) ;
F_4 ( V_7 , L_1 , V_10 , V_9 ) ;
return 0 ;
}
static int F_5 ( void * V_1 ,
const void * V_2 , T_1 V_11 ,
void * V_12 , T_1 V_13 )
{
struct V_4 * V_5 = V_1 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
T_2 * V_8 = ( T_2 * ) V_2 ;
T_2 * V_9 = ( T_2 * ) V_12 ;
void T_3 * V_10 = ( void * ) V_8 [ 0 ] ;
* V_9 = F_6 ( V_10 ) ;
F_4 ( V_7 , L_2 , V_10 , * V_9 ) ;
return 0 ;
}
static int F_7 ( struct V_4 * V_5 ,
struct V_14 * V_15 , enum V_16 V_10 )
{
if ( ! V_15 -> V_17 [ V_10 ] ) {
struct V_6 * V_7 = F_2 ( V_5 ) ;
F_8 ( V_7 , L_3 , V_10 ) ;
return 0 ;
}
return 1 ;
}
T_2 F_9 ( struct V_4 * V_5 ,
struct V_18 * V_19 , enum V_16 V_10 )
{
struct V_14 * V_15 = F_10 ( V_5 ) ;
T_2 V_9 ;
if ( ! F_7 ( V_5 , V_15 , V_10 ) )
return 0 ;
F_11 ( V_15 -> V_17 [ V_10 ] , F_12 ( V_19 ) , & V_9 ) ;
return V_9 ;
}
void F_13 ( struct V_4 * V_5 ,
struct V_18 * V_19 ,
enum V_16 V_10 , T_2 V_8 )
{
struct V_14 * V_15 = F_10 ( V_5 ) ;
if ( ! F_7 ( V_5 , V_15 , V_10 ) )
return;
F_14 ( V_15 -> V_17 [ V_10 ] , F_12 ( V_19 ) , V_8 ) ;
}
void F_15 ( struct V_4 * V_5 , struct V_18 * V_19 ,
enum V_16 V_10 , T_2 V_20 , T_2 V_8 )
{
struct V_14 * V_15 = F_10 ( V_5 ) ;
if ( ! F_7 ( V_5 , V_15 , V_10 ) )
return;
F_16 ( V_15 -> V_17 [ V_10 ] , F_12 ( V_19 ) ,
V_20 , V_8 ) ;
}
static int F_17 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_21 * V_22 )
{
int V_23 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
struct V_24 V_25 ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
V_25 . V_26 = 32 ;
V_25 . V_27 = 32 ;
V_15 -> V_28 = F_18 ( V_7 , & V_29 , V_5 , & V_25 ) ;
if ( F_19 ( V_15 -> V_28 ) ) {
F_8 ( V_7 , L_4 , F_20 ( V_15 -> V_28 ) ) ;
return F_20 ( V_15 -> V_28 ) ;
}
for ( V_23 = 0 ; V_23 < V_30 ; V_23 ++ ) {
V_15 -> V_17 [ V_23 ] = NULL ;
if ( ! V_22 [ V_23 ] . V_10 )
continue;
V_15 -> V_17 [ V_23 ] = F_21 ( V_7 , V_15 -> V_28 , V_22 [ V_23 ] ) ;
if ( F_19 ( V_15 -> V_17 [ V_23 ] ) )
return F_20 ( V_15 -> V_17 [ V_23 ] ) ;
}
return 0 ;
}
int F_22 ( struct V_4 * V_5 ,
struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_18 * V_19 ;
int V_35 ;
int V_36 ;
V_19 = F_23 ( V_5 ,
F_24 ( V_5 , V_32 ) ,
F_25 ( V_32 , V_34 ) ) ;
V_36 = F_12 ( V_19 ) ;
V_19 = F_26 ( V_5 , V_36 ) ;
V_35 = F_27 ( V_32 , V_19 , V_34 ) ;
if ( V_35 < 0 )
return V_35 ;
V_19 = F_28 ( V_5 , V_36 ) ;
V_35 = F_27 ( V_32 , V_19 , V_34 ) ;
return V_35 ;
}
int F_29 ( struct V_4 * V_5 ,
struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_18 * V_19 , * V_37 ;
int V_35 = 0 ;
F_30 (mod, n, io)
V_35 |= F_31 ( V_19 ) ;
return V_35 ;
}
static int F_32 ( struct V_4 * V_5 , struct V_14 * V_15 )
{
struct V_21 V_22 [ V_30 ] = {
F_33 ( V_15 , V_38 , V_39 , 0x800 ) ,
F_33 ( V_15 , V_38 , V_40 , 0x804 ) ,
F_34 ( V_15 , V_38 , V_41 , 0x18 , 0x80 ) ,
F_33 ( V_15 , V_42 , V_43 , 0x00 ) ,
F_33 ( V_15 , V_42 , V_44 , 0x04 ) ,
F_33 ( V_15 , V_42 , V_45 , 0x08 ) ,
F_33 ( V_15 , V_42 , V_46 , 0x0c ) ,
F_33 ( V_15 , V_42 , V_47 , 0x10 ) ,
F_33 ( V_15 , V_42 , V_48 , 0x14 ) ,
F_34 ( V_15 , V_49 , V_50 , 0x00 , 0x40 ) ,
F_34 ( V_15 , V_49 , V_51 , 0x04 , 0x40 ) ,
F_34 ( V_15 , V_49 , V_52 , 0x08 , 0x40 ) ,
F_34 ( V_15 , V_49 , V_53 , 0x0c , 0x40 ) ,
F_34 ( V_15 , V_49 , V_54 , 0x20 , 0x40 ) ,
} ;
return F_17 ( V_5 , V_15 , V_22 ) ;
}
static int F_35 ( struct V_55 * V_56 ,
struct V_57 * V_58 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
struct V_14 * V_15 = F_10 ( V_5 ) ;
struct V_59 * V_60 ;
struct V_59 * V_61 ;
struct V_59 * V_62 ;
struct V_59 * V_63 ;
int V_35 ;
V_60 = F_36 ( V_56 , V_64 , V_65 ) ;
V_61 = F_36 ( V_56 , V_64 , V_66 ) ;
V_62 = F_36 ( V_56 , V_64 , V_67 ) ;
V_63 = F_36 ( V_56 , V_64 , V_68 ) ;
V_15 -> V_69 [ V_65 ] = F_37 ( V_7 , V_60 ) ;
V_15 -> V_69 [ V_66 ] = F_37 ( V_7 , V_61 ) ;
V_15 -> V_69 [ V_67 ] = F_37 ( V_7 , V_62 ) ;
V_15 -> V_69 [ V_68 ] = F_37 ( V_7 , V_63 ) ;
if ( F_19 ( V_15 -> V_69 [ V_65 ] ) ||
F_19 ( V_15 -> V_69 [ V_66 ] ) ||
F_19 ( V_15 -> V_69 [ V_67 ] ) ||
F_19 ( V_15 -> V_69 [ V_68 ] ) )
return - V_70 ;
V_35 = F_32 ( V_5 , V_15 ) ;
if ( V_35 < 0 )
return V_35 ;
F_4 ( V_7 , L_5 ) ;
F_4 ( V_7 , L_6 , V_60 -> V_71 ,
V_15 -> V_69 [ V_65 ] ) ;
F_4 ( V_7 , L_7 , V_61 -> V_71 ,
V_15 -> V_69 [ V_66 ] ) ;
F_4 ( V_7 , L_8 , V_62 -> V_71 ,
V_15 -> V_69 [ V_67 ] ) ;
F_4 ( V_7 , L_9 , V_63 -> V_71 ,
V_15 -> V_69 [ V_68 ] ) ;
return 0 ;
}
static int F_38 ( struct V_4 * V_5 , struct V_14 * V_15 )
{
struct V_21 V_22 [ V_30 ] = {
F_39 ( V_15 , V_72 , V_73 , 0x00 ) ,
F_39 ( V_15 , V_72 , V_74 , 0x08 ) ,
F_39 ( V_15 , V_72 , V_75 , 0x0c ) ,
F_39 ( V_15 , V_72 , V_76 , 0x10 ) ,
F_39 ( V_15 , V_72 , V_77 , 0xc0 ) ,
F_39 ( V_15 , V_72 , V_39 , 0xD0 ) ,
F_39 ( V_15 , V_72 , V_40 , 0xD4 ) ,
F_40 ( V_15 , V_72 , V_78 , 0x20 , 0x4 ) ,
F_40 ( V_15 , V_72 , V_79 , 0x50 , 0x8 ) ,
F_40 ( V_15 , V_72 , V_80 , 0x200 , 0x40 ) ,
F_40 ( V_15 , V_72 , V_81 , 0x204 , 0x40 ) ,
F_40 ( V_15 , V_72 , V_82 , 0x214 , 0x40 ) ,
F_40 ( V_15 , V_72 , V_83 , 0x21c , 0x40 ) ,
F_40 ( V_15 , V_72 , V_84 , 0x220 , 0x40 ) ,
F_40 ( V_15 , V_72 , V_85 , 0x224 , 0x40 ) ,
F_40 ( V_15 , V_72 , V_86 , 0x228 , 0x40 ) ,
F_39 ( V_15 , V_42 , V_43 , 0x00 ) ,
F_39 ( V_15 , V_42 , V_44 , 0x04 ) ,
F_39 ( V_15 , V_42 , V_45 , 0x08 ) ,
F_39 ( V_15 , V_42 , V_46 , 0x0c ) ,
F_39 ( V_15 , V_42 , V_47 , 0x10 ) ,
F_39 ( V_15 , V_42 , V_87 , 0x18 ) ,
F_39 ( V_15 , V_42 , V_88 , 0x1c ) ,
F_39 ( V_15 , V_42 , V_89 , 0x20 ) ,
F_40 ( V_15 , V_49 , V_50 , 0x00 , 0x40 ) ,
F_40 ( V_15 , V_49 , V_51 , 0x04 , 0x40 ) ,
F_40 ( V_15 , V_49 , V_52 , 0x08 , 0x40 ) ,
F_40 ( V_15 , V_49 , V_53 , 0x0c , 0x40 ) ,
F_40 ( V_15 , V_49 , V_54 , 0x20 , 0x40 ) ,
} ;
return F_17 ( V_5 , V_15 , V_22 ) ;
}
static int F_41 ( struct V_55 * V_56 ,
struct V_57 * V_58 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
struct V_14 * V_15 = F_10 ( V_5 ) ;
struct V_59 * V_90 ;
struct V_59 * V_61 ;
struct V_59 * V_63 ;
int V_35 ;
V_90 = F_36 ( V_56 , V_64 , V_91 ) ;
V_61 = F_36 ( V_56 , V_64 , V_92 ) ;
V_63 = F_36 ( V_56 , V_64 , V_93 ) ;
V_15 -> V_69 [ V_91 ] = F_37 ( V_7 , V_90 ) ;
V_15 -> V_69 [ V_92 ] = F_37 ( V_7 , V_61 ) ;
V_15 -> V_69 [ V_93 ] = F_37 ( V_7 , V_63 ) ;
if ( F_19 ( V_15 -> V_69 [ V_91 ] ) ||
F_19 ( V_15 -> V_69 [ V_92 ] ) ||
F_19 ( V_15 -> V_69 [ V_93 ] ) )
return - V_70 ;
V_35 = F_38 ( V_5 , V_15 ) ;
if ( V_35 < 0 )
return V_35 ;
F_4 ( V_7 , L_10 ) ;
F_4 ( V_7 , L_11 , V_90 -> V_71 ,
V_15 -> V_69 [ V_91 ] ) ;
F_4 ( V_7 , L_12 , V_61 -> V_71 ,
V_15 -> V_69 [ V_92 ] ) ;
F_4 ( V_7 , L_13 , V_63 -> V_71 ,
V_15 -> V_69 [ V_93 ] ) ;
return 0 ;
}
int F_42 ( struct V_55 * V_56 ,
struct V_57 * V_58 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
struct V_14 * V_15 ;
int V_35 ;
V_15 = F_43 ( V_7 , sizeof( * V_15 ) , V_94 ) ;
if ( ! V_15 ) {
F_8 ( V_7 , L_14 ) ;
return - V_95 ;
}
V_5 -> V_15 = V_15 ;
V_35 = - V_70 ;
if ( F_44 ( V_5 ) )
V_35 = F_41 ( V_56 , V_58 , V_5 ) ;
else if ( F_45 ( V_5 ) )
V_35 = F_35 ( V_56 , V_58 , V_5 ) ;
if ( V_35 < 0 )
F_8 ( V_7 , L_15 ) ;
return V_35 ;
}
void F_46 ( struct V_55 * V_56 ,
struct V_4 * V_5 )
{
}
