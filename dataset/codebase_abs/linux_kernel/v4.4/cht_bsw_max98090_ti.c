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
struct V_27 * V_28 = & V_26 -> V_3 -> V_28 ;
if ( V_23 & V_29 ) {
F_6 ( V_28 , L_2 ) ;
F_6 ( V_28 , L_3 ) ;
F_7 ( V_28 ) ;
} else {
F_8 ( V_28 , L_3 ) ;
F_8 ( V_28 , L_2 ) ;
F_7 ( V_28 ) ;
}
return 0 ;
}
static int F_9 ( struct V_6 * V_30 )
{
int V_16 ;
int V_31 ;
struct V_32 * V_33 = F_10 ( V_30 -> V_3 ) ;
struct V_25 * V_26 = & V_33 -> V_26 ;
if ( V_33 -> V_34 )
V_31 = V_35 | V_29 |
V_36 | V_37 |
V_38 | V_39 ;
else
V_31 = V_35 | V_29 ;
V_16 = F_11 ( V_30 -> V_3 , L_4 ,
V_31 , V_26 , NULL , 0 ) ;
if ( V_16 ) {
F_4 ( V_30 -> V_20 , L_5 , V_16 ) ;
return V_16 ;
}
if ( V_33 -> V_34 )
F_12 ( V_26 , & V_40 ) ;
return V_16 ;
}
static int F_13 ( struct V_6 * V_7 ,
struct V_13 * V_14 )
{
struct V_41 * V_42 = F_14 ( V_14 ,
V_43 ) ;
struct V_41 * V_44 = F_14 ( V_14 ,
V_45 ) ;
int V_16 = 0 ;
unsigned int V_46 = 0 ;
V_16 = F_15 ( V_7 -> V_47 , 0x3 , 0x3 , 2 , 16 ) ;
if ( V_16 < 0 ) {
F_4 ( V_7 -> V_20 , L_6 , V_16 ) ;
return V_16 ;
}
V_46 = V_48 | V_49
| V_50 ;
V_16 = F_16 ( V_7 -> V_47 , V_46 ) ;
if ( V_16 < 0 ) {
F_4 ( V_7 -> V_20 , L_7 , V_16 ) ;
return V_16 ;
}
V_42 -> V_51 = V_42 -> V_52 = 48000 ;
V_44 -> V_51 = V_44 -> V_52 = 2 ;
F_17 ( V_14 , V_53 ) ;
return 0 ;
}
static int F_18 ( struct V_11 * V_12 )
{
return F_19 ( V_12 -> V_30 ,
V_43 , 48000 ) ;
}
static int F_20 ( struct V_54 * V_55 )
{
struct V_2 * V_3 = V_55 -> V_3 ;
struct V_32 * V_33 = F_10 ( V_3 ) ;
return F_21 ( V_55 , & V_33 -> V_26 ) ;
}
static T_1 F_22 ( T_2 V_56 , T_3 V_57 ,
void * V_58 , void * * V_16 )
{
* ( bool * ) V_58 = true ;
return V_59 ;
}
static int F_23 ( struct V_60 * V_61 )
{
int V_62 = 0 ;
bool V_63 = false ;
struct V_32 * V_64 ;
V_64 = F_24 ( & V_61 -> V_20 , sizeof( * V_64 ) , V_65 ) ;
if ( ! V_64 )
return - V_66 ;
if ( F_25 ( F_26 (
L_8 ,
F_22 ,
& V_63 , NULL ) ) && V_63 ) {
V_64 -> V_34 = true ;
} else {
V_67 . V_68 = NULL ;
V_67 . V_69 = 0 ;
V_64 -> V_34 = false ;
}
V_67 . V_20 = & V_61 -> V_20 ;
F_27 ( & V_67 , V_64 ) ;
V_62 = F_28 ( & V_61 -> V_20 , & V_67 ) ;
if ( V_62 ) {
F_4 ( & V_61 -> V_20 ,
L_9 , V_62 ) ;
return V_62 ;
}
F_29 ( V_61 , & V_67 ) ;
return V_62 ;
}
