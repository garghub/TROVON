static inline struct V_1 * F_1 ( struct V_1 * V_2 ,
int V_3 )
{
if ( V_2 )
return V_2 ;
if ( F_2 ( V_3 >= F_3 () ) )
return NULL ;
if ( F_2 ( V_3 < 0 ) )
V_3 = F_4 () ;
return V_4 [ V_3 ] ;
}
static inline struct V_1 * F_5 ( struct V_1 * V_2 )
{
if ( V_2 )
return V_2 ;
F_6 ( & V_5 ) ;
V_2 = F_7 ( V_6 . V_7 , struct V_1 , V_8 ) ;
F_8 ( & V_2 -> V_8 ) ;
F_9 ( & V_2 -> V_8 , & V_6 ) ;
F_10 ( & V_5 ) ;
return V_2 ;
}
struct V_1 * F_11 ( const struct V_9 * V_10 )
{
struct V_1 * V_11 = F_12 ( sizeof( * V_11 ) , V_12 ) ;
if ( ! V_11 )
return NULL ;
if ( V_10 -> V_3 >= F_3 () ) {
F_13 ( V_11 ) ;
return NULL ;
}
F_14 ( & V_11 -> V_13 , 1 ) ;
V_11 -> V_14 = * V_10 ;
V_11 -> V_15 . V_16 = V_11 -> V_14 . V_17 ;
V_11 -> V_15 . V_18 = V_11 -> V_14 . V_19 ;
V_11 -> V_15 . V_20 = V_11 -> V_14 . V_20 ;
V_11 -> V_21 = F_15 ( & V_11 -> V_15 ) ;
if ( ! V_11 -> V_21 ) {
F_13 ( V_11 ) ;
return NULL ;
}
F_16 ( & V_11 -> V_8 ) ;
F_17 ( & V_11 -> V_22 ) ;
F_17 ( & V_11 -> V_23 ) ;
F_16 ( & V_11 -> V_24 ) ;
F_18 ( V_11 -> V_21 ,
V_25 ) ;
F_19 ( V_11 -> V_21 , 0xffffffff ) ;
if ( V_11 -> V_14 . V_26 )
F_20 ( V_11 -> V_21 , 0 , 1 ) ;
F_6 ( & V_5 ) ;
F_9 ( & V_11 -> V_8 , & V_6 ) ;
if ( V_10 -> V_3 >= 0 && ! V_4 [ V_10 -> V_3 ] )
V_4 [ V_10 -> V_3 ] = V_11 ;
F_10 ( & V_5 ) ;
return V_11 ;
}
void F_21 ( struct V_1 * V_2 )
{
if ( ! F_22 ( & V_2 -> V_13 ) )
return;
F_13 ( V_2 ) ;
}
T_1 F_23 ( struct V_1 * V_11 )
{
const struct V_27 * V_28 ;
int V_29 = 0 ;
struct V_30 * V_21 ;
T_2 V_31 ;
V_21 = V_11 -> V_21 ;
V_31 = F_24 ( V_21 ) ;
if ( ! V_31 )
return V_32 ;
V_28 = F_25 ( V_21 ) ;
while ( V_28 ) {
if ( F_26 ( V_28 ) ) {
struct V_33 * V_34 ;
T_3 V_35 ;
V_35 = F_27 ( V_28 ) ;
V_34 = ( void * ) V_35 ;
V_34 -> V_36 ( V_34 ) ;
} else {
F_28 ( L_1 ) ;
}
F_29 ( V_21 , V_28 ) ;
++ V_29 ;
if ( V_29 > V_37 )
goto V_38;
V_28 = F_25 ( V_21 ) ;
}
V_38:
F_19 ( V_21 , V_31 ) ;
F_30 ( V_21 , 0 ) ;
return V_39 ;
}
int F_31 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
unsigned long V_40 ;
V_2 = F_1 ( V_2 , V_34 -> V_41 ) ;
if ( ! V_2 )
return - V_42 ;
V_34 -> V_43 = V_2 -> V_14 . V_43 ;
V_34 -> V_44 = ( T_3 ) V_34 ;
V_34 -> V_45 = V_2 ;
F_32 ( & V_2 -> V_23 , V_40 ) ;
F_33 ( & V_34 -> V_8 , & V_2 -> V_24 ) ;
F_34 ( & V_2 -> V_23 , V_40 ) ;
if ( V_34 -> V_46 )
return F_35 ( V_2 -> V_21 ,
( V_47 ) V_34 -> V_48 ,
V_34 -> V_44 ) ;
return 0 ;
}
void F_36 ( struct V_1 * V_49 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_45 ;
unsigned long V_40 ;
if ( V_34 -> V_46 )
F_37 ( V_2 -> V_21 , ( V_47 ) V_34 -> V_48 ) ;
F_32 ( & V_2 -> V_23 , V_40 ) ;
F_8 ( & V_34 -> V_8 ) ;
F_34 ( & V_2 -> V_23 , V_40 ) ;
}
int F_38 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
unsigned long V_40 ;
int V_50 ;
V_2 = F_1 ( V_2 , V_34 -> V_41 ) ;
if ( ! F_2 ( V_2 ) )
return - V_42 ;
F_32 ( & V_2 -> V_22 , V_40 ) ;
if ( V_34 -> V_46 )
V_50 = F_39 ( V_2 -> V_21 , ( V_47 ) V_34 -> V_48 ) ;
else
V_50 = F_40 ( V_2 -> V_21 , V_34 -> V_48 ) ;
F_34 ( & V_2 -> V_22 , V_40 ) ;
return V_50 ;
}
int F_41 ( struct V_1 * V_2 , T_2 V_51 ,
struct V_52 * V_53 )
{
struct V_54 V_55 ;
int V_50 ;
F_42 ( & V_55 ) ;
F_43 ( & V_55 , V_53 -> V_56 , V_53 -> V_57 , 1 ) ;
F_44 ( & V_55 , ( V_58 ) V_53 -> V_29 ) ;
F_45 ( & V_55 , V_51 ) ;
V_2 = F_5 ( V_2 ) ;
if ( ! V_2 )
return - V_42 ;
V_53 -> V_21 = V_2 -> V_21 ;
V_50 = F_46 ( V_2 -> V_21 , & V_55 ) ;
if ( V_50 )
V_53 -> V_21 = NULL ;
return V_50 ;
}
int F_47 ( struct V_1 * V_2 , T_2 V_59 ,
struct V_52 * V_53 )
{
struct V_54 V_55 ;
int V_50 ;
F_42 ( & V_55 ) ;
F_43 ( & V_55 , V_53 -> V_56 , V_53 -> V_57 , 1 ) ;
F_44 ( & V_55 , ( V_58 ) V_53 -> V_29 ) ;
F_48 ( & V_55 , V_59 , V_60 ) ;
V_2 = F_5 ( V_2 ) ;
if ( ! V_2 )
return - V_42 ;
V_53 -> V_21 = V_2 -> V_21 ;
V_50 = F_46 ( V_2 -> V_21 , & V_55 ) ;
if ( V_50 )
V_53 -> V_21 = NULL ;
return V_50 ;
}
int F_49 ( struct V_1 * V_2 ,
T_2 V_51 ,
const struct V_61 * V_62 )
{
struct V_63 V_64 ;
V_2 = F_5 ( V_2 ) ;
if ( ! V_2 )
return - V_42 ;
F_50 ( & V_64 ) ;
F_51 ( & V_64 , 0 ) ;
F_52 ( & V_64 , V_51 ) ;
return F_53 ( V_2 -> V_21 , & V_64 , V_62 ) ;
}
int F_54 ( struct V_1 * V_2 ,
T_2 V_65 , V_58 V_66 , V_47 V_67 ,
const struct V_61 * V_62 )
{
struct V_63 V_64 ;
V_2 = F_5 ( V_2 ) ;
if ( ! V_2 )
return - V_42 ;
F_50 ( & V_64 ) ;
F_51 ( & V_64 , 0 ) ;
F_55 ( & V_64 , V_65 , V_67 , V_66 ) ;
return F_53 ( V_2 -> V_21 , & V_64 , V_62 ) ;
}
int F_56 ( struct V_1 * V_2 ,
T_2 V_68 ,
const T_3 * V_69 ,
unsigned int V_70 )
{
struct V_71 V_72 ;
V_2 = F_5 ( V_2 ) ;
if ( ! V_2 )
return - V_42 ;
F_57 ( & V_72 ) ;
F_58 ( & V_72 , V_68 ) ;
return F_59 ( V_2 -> V_21 , & V_72 , V_69 , V_70 ) ;
}
int F_60 ( struct V_1 * V_2 ,
T_2 V_68 ,
T_3 * V_69 ,
unsigned int V_70 )
{
unsigned long V_40 ;
int V_50 ;
V_2 = F_5 ( V_2 ) ;
if ( ! V_2 )
return - V_42 ;
F_32 ( & V_2 -> V_22 , V_40 ) ;
V_50 = F_61 ( V_2 -> V_21 , V_68 , V_69 , V_70 ) ;
F_34 ( & V_2 -> V_22 , V_40 ) ;
return V_50 ;
}
struct V_52 * F_62 ( unsigned int V_73 ,
struct V_74 * V_75 )
{
struct V_52 * V_76 ;
T_4 V_77 ;
if ( ! V_73 || ( V_73 > 16 ) )
return NULL ;
V_76 = F_12 ( sizeof( * V_76 ) , V_12 ) ;
if ( ! V_76 )
return NULL ;
V_76 -> V_29 = V_73 ;
V_77 = V_73 * sizeof( struct V_27 ) + 64 ;
V_76 -> V_78 = F_63 ( V_77 , V_12 ) ;
if ( ! V_76 -> V_78 ) {
F_13 ( V_76 ) ;
return NULL ;
}
V_76 -> V_56 = F_64 ( V_76 -> V_78 , 64 ) ;
V_76 -> V_57 = F_65 ( V_75 , V_76 -> V_56 ,
sizeof( struct V_27 ) * V_73 ,
V_79 ) ;
if ( F_66 ( V_75 , V_76 -> V_57 ) ) {
F_13 ( V_76 -> V_78 ) ;
F_13 ( V_76 ) ;
return NULL ;
}
V_76 -> V_80 = 0 ;
V_76 -> V_75 = V_75 ;
return V_76 ;
}
void F_67 ( struct V_52 * V_53 )
{
F_68 ( V_53 -> V_75 , V_53 -> V_57 , sizeof( struct V_27 ) * V_53 -> V_29 ,
V_79 ) ;
F_13 ( V_53 -> V_78 ) ;
F_13 ( V_53 ) ;
}
struct V_27 * F_69 ( struct V_52 * V_53 , int * V_81 )
{
int V_82 ;
struct V_27 * V_76 = & V_53 -> V_56 [ V_53 -> V_80 ] ;
V_82 = F_70 ( V_53 -> V_21 , V_76 ) ;
if ( ! V_82 ) {
* V_81 = 0 ;
return NULL ;
}
V_53 -> V_80 ++ ;
if ( F_71 ( V_76 ) ) {
* V_81 = 1 ;
V_53 -> V_80 = 0 ;
if ( ! ( F_72 ( V_76 ) & V_83 ) )
V_76 = NULL ;
} else {
* V_81 = 0 ;
}
return V_76 ;
}
