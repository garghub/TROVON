static inline struct V_1 * F_1 (
struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline int F_3 ( T_1 * * V_5 , unsigned int * V_6 ,
const T_1 * V_7 , T_2 V_8 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ )
if ( V_7 [ V_9 ] )
break;
* V_6 = V_8 - V_9 ;
* V_5 = F_4 ( * V_6 , V_10 ) ;
if ( ! * V_5 )
return - V_11 ;
memcpy ( * V_5 , V_7 + V_9 , * V_6 ) ;
return 0 ;
}
static int F_5 ( struct V_2 * V_12 , int V_13 )
{
struct V_1 * V_3 = F_1 ( V_12 ) ;
struct V_14 * V_15 = F_6 ( V_3 ) ;
if ( V_13 )
return V_13 ;
V_3 -> V_16 = V_15 -> V_17 . V_18 . V_19 . V_20 >> 3 ;
return 0 ;
}
static unsigned int F_7 ( struct V_21 * V_22 )
{
if ( F_8 () > F_9 ( 3 , 0 ) )
return V_23 ;
else
return V_24 ;
}
static int F_10 ( struct V_1 * V_3 , bool V_25 )
{
struct V_21 * V_22 = F_11 ( V_3 ) ;
struct V_26 * V_27 = F_12 ( V_22 ) ;
struct V_14 * V_15 = F_6 ( V_3 ) ;
int V_13 = 0 ;
memset ( & V_15 -> V_17 , 0 , sizeof( V_15 -> V_17 ) ) ;
F_13 ( & V_15 -> V_17 . V_28 ) ;
V_15 -> V_17 . V_29 = V_30 ;
V_15 -> V_17 . V_18 . V_19 . V_20 = V_27 -> V_18 . V_19 . V_31 ;
if ( V_25 ) {
V_15 -> V_17 . V_18 . V_19 . exp = & V_27 -> V_18 . V_19 . V_32 ;
V_15 -> V_17 . V_18 . V_19 . V_33 = V_27 -> V_18 . V_19 . V_34 ;
} else {
V_15 -> V_17 . V_18 . V_19 . exp = & V_27 -> V_18 . V_19 . V_35 ;
V_15 -> V_17 . V_18 . V_19 . V_33 = V_27 -> V_18 . V_19 . V_36 ;
}
V_15 -> V_17 . V_18 . V_19 . V_37 = & V_27 -> V_18 . V_19 . V_38 ;
V_15 -> V_17 . V_18 . V_19 . V_39 = V_27 -> V_18 . V_19 . V_40 ;
V_15 -> V_17 . V_18 . V_19 . V_41 = V_3 -> V_41 ;
V_15 -> V_17 . V_18 . V_19 . V_42 = V_3 -> V_42 ;
V_15 -> V_17 . V_18 . V_19 . V_43 = V_3 -> V_43 ;
V_13 = F_14 ( & V_3 -> V_4 , & V_15 -> V_17 ) ;
return V_13 ;
}
static int F_15 ( struct V_1 * V_3 )
{
return F_10 ( V_3 , true ) ;
}
static int F_16 ( struct V_1 * V_3 )
{
return F_10 ( V_3 , false ) ;
}
static int F_17 ( unsigned int V_44 )
{
if ( V_44 < 8 || V_44 > 4096 )
return - V_45 ;
return 0 ;
}
static void F_18 ( struct V_26 * V_27 )
{
F_19 ( V_27 -> V_18 . V_19 . V_46 ) ;
V_27 -> V_18 . V_19 . V_46 = NULL ;
V_27 -> V_18 . V_19 . V_34 = 0 ;
F_19 ( V_27 -> V_18 . V_19 . V_47 ) ;
V_27 -> V_18 . V_19 . V_47 = NULL ;
V_27 -> V_18 . V_19 . V_40 = 0 ;
F_19 ( V_27 -> V_18 . V_19 . V_48 ) ;
V_27 -> V_18 . V_19 . V_48 = NULL ;
V_27 -> V_18 . V_19 . V_36 = 0 ;
}
static int F_20 ( struct V_21 * V_22 , const void * V_49 ,
unsigned int V_50 , bool V_51 )
{
struct V_26 * V_27 = F_12 ( V_22 ) ;
struct V_52 V_53 ;
int V_13 ;
F_18 ( V_27 ) ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
if ( V_51 )
V_13 = F_21 ( & V_53 , V_49 , V_50 ) ;
else
V_13 = F_22 ( & V_53 , V_49 , V_50 ) ;
if ( V_13 )
goto V_54;
V_13 = F_3 ( & V_27 -> V_18 . V_19 . V_47 , & V_27 -> V_18 . V_19 . V_40 ,
V_53 . V_55 , V_53 . V_56 ) ;
if ( V_13 )
goto V_57;
F_23 ( & V_27 -> V_18 . V_19 . V_38 , V_27 -> V_18 . V_19 . V_47 , V_27 -> V_18 . V_19 . V_40 ) ;
V_27 -> V_18 . V_19 . V_31 = V_27 -> V_18 . V_19 . V_40 << 3 ;
if ( F_17 ( V_27 -> V_18 . V_19 . V_31 ) ) {
V_13 = - V_45 ;
goto V_57;
}
V_13 = F_3 ( & V_27 -> V_18 . V_19 . V_46 , & V_27 -> V_18 . V_19 . V_34 ,
V_53 . V_58 , V_53 . V_59 ) ;
if ( V_13 )
goto V_57;
F_23 ( & V_27 -> V_18 . V_19 . V_32 , V_27 -> V_18 . V_19 . V_46 , V_27 -> V_18 . V_19 . V_34 ) ;
if ( V_51 ) {
V_13 = F_3 ( & V_27 -> V_18 . V_19 . V_48 ,
& V_27 -> V_18 . V_19 . V_36 ,
V_53 . V_60 , V_53 . V_61 ) ;
if ( V_13 )
goto V_57;
F_23 ( & V_27 -> V_18 . V_19 . V_35 ,
V_27 -> V_18 . V_19 . V_48 , V_27 -> V_18 . V_19 . V_36 ) ;
}
return 0 ;
V_57:
F_18 ( V_27 ) ;
V_54:
return V_13 ;
}
static int F_24 ( struct V_21 * V_22 , const void * V_49 ,
unsigned int V_50 )
{
return F_20 ( V_22 , V_49 , V_50 , true ) ;
}
static int F_25 ( struct V_21 * V_22 , const void * V_49 ,
unsigned int V_50 )
{
return F_20 ( V_22 , V_49 , V_50 , false ) ;
}
static int F_26 ( struct V_21 * V_22 )
{
struct V_26 * V_27 = F_12 ( V_22 ) ;
F_27 ( V_22 , sizeof( struct V_14 ) ) ;
V_27 -> V_62 = F_5 ;
return 0 ;
}
static void F_28 ( struct V_21 * V_22 )
{
struct V_26 * V_27 = F_29 ( & V_22 -> V_4 ) ;
F_18 ( V_27 ) ;
}
int F_30 ( struct V_63 * V_64 , const struct V_65 * V_66 )
{
struct V_67 * V_68 ;
struct V_69 * V_70 ;
int V_13 ;
V_68 = F_4 ( sizeof( * V_68 ) , V_10 ) ;
if ( ! V_68 )
return - V_11 ;
F_13 ( & V_68 -> V_28 ) ;
V_70 = & V_68 -> V_70 ;
* V_70 = * V_66 -> V_71 ;
snprintf ( V_70 -> V_4 . V_72 , V_73 , L_1 , V_66 -> V_74 ) ;
snprintf ( V_70 -> V_4 . V_75 , V_73 , L_1 ,
V_66 -> V_76 ) ;
V_13 = F_31 ( V_70 ) ;
if ( V_13 ) {
F_32 ( L_2 ,
V_70 -> V_4 . V_72 , V_13 ) ;
F_33 ( V_68 ) ;
return V_13 ;
}
F_34 ( & V_68 -> V_28 , V_64 ) ;
return 0 ;
}
int F_35 ( struct V_63 * V_64 )
{
int V_77 , V_13 ;
unsigned int V_78 = F_8 () ;
for ( V_77 = 0 ; V_77 < F_36 ( V_79 ) ; V_77 ++ ) {
if ( V_79 [ V_77 ] . V_80 > V_78 )
continue;
V_13 = F_30 ( V_64 , & V_79 [ V_77 ] ) ;
if ( V_13 )
return V_13 ;
}
return 0 ;
}
