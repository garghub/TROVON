static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 -> V_5 ; V_4 ++ ) {
struct V_6 * V_7 ;
V_7 = V_3 -> V_7 + V_4 ;
if ( ! strncmp ( V_7 -> V_8 -> V_9 , V_10 ,
strlen ( V_10 ) ) )
return V_7 -> V_8 ;
}
return NULL ;
}
static int F_2 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_6 * V_7 = V_12 -> V_15 ;
struct V_1 * V_8 = V_7 -> V_8 ;
int V_16 ;
V_16 = F_3 ( V_8 , V_17 ,
V_18 , V_19 ) ;
if ( V_16 < 0 ) {
F_4 ( V_7 -> V_20 , L_1 , V_16 ) ;
return V_16 ;
}
return 0 ;
}
static int F_5 ( struct V_21 * V_22 ,
unsigned long V_23 , void * V_24 )
{
struct V_25 * V_26 = (struct V_25 * ) V_24 ;
struct V_1 * V_8 = V_26 -> V_3 -> V_7 -> V_8 ;
struct V_27 * V_28 = V_8 -> V_28 ;
if ( V_23 & V_29 ) {
F_6 ( & V_28 -> V_30 , L_2 ) ;
F_6 ( & V_28 -> V_30 , L_3 ) ;
F_7 ( & V_28 -> V_30 ) ;
} else {
F_8 ( & V_28 -> V_30 , L_3 ) ;
F_8 ( & V_28 -> V_30 , L_2 ) ;
F_7 ( & V_28 -> V_30 ) ;
}
return 0 ;
}
static int F_9 ( struct V_6 * V_31 )
{
int V_16 ;
int V_32 ;
struct V_33 * V_34 = F_10 ( V_31 -> V_3 ) ;
struct V_25 * V_26 = & V_34 -> V_26 ;
if ( V_34 -> V_35 )
V_32 = V_36 | V_29 |
V_37 | V_38 |
V_39 | V_40 ;
else
V_32 = V_36 | V_29 ;
V_16 = F_11 ( V_31 -> V_3 , L_4 ,
V_32 , V_26 , NULL , 0 ) ;
if ( V_16 ) {
F_4 ( V_31 -> V_20 , L_5 , V_16 ) ;
return V_16 ;
}
if ( V_34 -> V_35 )
F_12 ( V_26 , & V_41 ) ;
return V_16 ;
}
static int F_13 ( struct V_6 * V_7 ,
struct V_13 * V_14 )
{
struct V_42 * V_43 = F_14 ( V_14 ,
V_44 ) ;
struct V_42 * V_45 = F_14 ( V_14 ,
V_46 ) ;
int V_16 = 0 ;
unsigned int V_47 = 0 ;
V_16 = F_15 ( V_7 -> V_48 , 0x3 , 0x3 , 2 , 16 ) ;
if ( V_16 < 0 ) {
F_4 ( V_7 -> V_20 , L_6 , V_16 ) ;
return V_16 ;
}
V_47 = V_49 | V_50
| V_51 ;
V_16 = F_16 ( V_7 -> V_48 , V_47 ) ;
if ( V_16 < 0 ) {
F_4 ( V_7 -> V_20 , L_7 , V_16 ) ;
return V_16 ;
}
V_43 -> V_52 = V_43 -> V_53 = 48000 ;
V_45 -> V_52 = V_45 -> V_53 = 2 ;
F_17 ( V_14 , V_54 ) ;
return 0 ;
}
static int F_18 ( struct V_11 * V_12 )
{
return F_19 ( V_12 -> V_31 , 0 ,
V_44 ,
& V_55 ) ;
}
static int F_20 ( struct V_56 * V_57 )
{
struct V_2 * V_3 = V_57 -> V_3 ;
struct V_33 * V_34 = F_10 ( V_3 ) ;
return F_21 ( V_57 , & V_34 -> V_26 ) ;
}
static T_1 F_22 ( T_2 V_58 , T_3 V_59 ,
void * V_60 , void * * V_16 )
{
* ( bool * ) V_60 = true ;
return V_61 ;
}
static int F_23 ( struct V_62 * V_63 )
{
int V_64 = 0 ;
bool V_65 = false ;
struct V_33 * V_66 ;
V_66 = F_24 ( & V_63 -> V_20 , sizeof( * V_66 ) , V_67 ) ;
if ( ! V_66 )
return - V_68 ;
if ( F_25 ( F_26 (
L_8 ,
F_22 ,
& V_65 , NULL ) ) && V_65 ) {
V_66 -> V_35 = true ;
} else {
V_69 . V_70 = NULL ;
V_69 . V_71 = 0 ;
V_66 -> V_35 = false ;
}
V_69 . V_20 = & V_63 -> V_20 ;
F_27 ( & V_69 , V_66 ) ;
V_64 = F_28 ( & V_63 -> V_20 , & V_69 ) ;
if ( V_64 ) {
F_4 ( & V_63 -> V_20 ,
L_9 , V_64 ) ;
return V_64 ;
}
F_29 ( V_63 , & V_69 ) ;
return V_64 ;
}
