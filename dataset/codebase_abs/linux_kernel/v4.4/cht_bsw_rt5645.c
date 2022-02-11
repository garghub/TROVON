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
struct V_13 * V_14 , int V_15 )
{
struct V_16 * V_17 = V_12 -> V_17 ;
struct V_2 * V_3 = V_17 -> V_3 ;
struct V_1 * V_8 ;
int V_18 ;
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 ) {
F_3 ( V_3 -> V_19 , L_1 ) ;
return - V_20 ;
}
if ( ! F_4 ( V_15 ) )
return 0 ;
V_18 = F_5 ( V_8 , V_21 ,
0 , V_22 ) ;
if ( V_18 < 0 ) {
F_3 ( V_3 -> V_19 , L_2 , V_18 ) ;
return V_18 ;
}
return 0 ;
}
static int F_6 ( struct V_23 * V_24 ,
struct V_25 * V_26 )
{
struct V_6 * V_7 = V_24 -> V_27 ;
struct V_1 * V_8 = V_7 -> V_8 ;
int V_18 ;
V_18 = F_7 ( V_8 , 0 , V_28 ,
V_29 , F_8 ( V_26 ) * 512 ) ;
if ( V_18 < 0 ) {
F_3 ( V_7 -> V_19 , L_3 , V_18 ) ;
return V_18 ;
}
V_18 = F_5 ( V_8 , V_30 ,
F_8 ( V_26 ) * 512 , V_22 ) ;
if ( V_18 < 0 ) {
F_3 ( V_7 -> V_19 , L_2 , V_18 ) ;
return V_18 ;
}
return 0 ;
}
static int F_9 ( struct V_6 * V_31 )
{
int V_18 ;
int V_32 ;
struct V_33 * V_34 = V_31 -> V_34 ;
struct V_1 * V_8 = V_31 -> V_8 ;
struct V_35 * V_36 = F_10 ( V_31 -> V_3 ) ;
F_11 ( V_34 ,
V_37 |
V_38 |
V_39 |
V_40 ,
V_41 ) ;
V_18 = F_12 ( V_8 , 0xF , 0xF , 4 , 24 ) ;
if ( V_18 < 0 ) {
F_3 ( V_31 -> V_19 , L_4 , V_18 ) ;
return V_18 ;
}
if ( V_36 -> V_42 -> V_43 == V_44 )
V_32 = V_45 | V_46 |
V_47 | V_48 |
V_49 | V_50 ;
else
V_32 = V_45 | V_46 ;
V_18 = F_13 ( V_31 -> V_3 , L_5 ,
V_32 , & V_36 -> V_51 ,
NULL , 0 ) ;
if ( V_18 ) {
F_3 ( V_31 -> V_19 , L_6 , V_18 ) ;
return V_18 ;
}
F_14 ( V_34 , & V_36 -> V_51 , & V_36 -> V_51 , & V_36 -> V_51 ) ;
return V_18 ;
}
static int F_15 ( struct V_6 * V_7 ,
struct V_25 * V_26 )
{
struct V_52 * V_53 = F_16 ( V_26 ,
V_54 ) ;
struct V_52 * V_55 = F_16 ( V_26 ,
V_56 ) ;
V_53 -> V_57 = V_53 -> V_58 = 48000 ;
V_55 -> V_57 = V_55 -> V_58 = 2 ;
F_17 ( V_26 , V_59 ) ;
return 0 ;
}
static int F_18 ( struct V_23 * V_24 )
{
return F_19 ( V_24 -> V_31 ,
V_54 , 48000 ) ;
}
static T_1 F_20 ( T_2 V_60 , T_3 V_61 ,
void * V_62 , void * * V_18 )
{
* ( bool * ) V_62 = true ;
return V_63 ;
}
static int F_21 ( struct V_64 * V_65 )
{
int V_66 = 0 ;
int V_4 ;
struct V_35 * V_67 ;
struct V_2 * V_3 = V_68 [ 0 ] . V_69 ;
bool V_70 = false ;
char V_71 [ 16 ] ;
V_67 = F_22 ( & V_65 -> V_19 , sizeof( * V_67 ) , V_72 ) ;
if ( ! V_67 )
return - V_73 ;
for ( V_4 = 0 ; V_4 < F_23 ( V_68 ) ; V_4 ++ ) {
if ( F_24 ( F_25 (
V_68 [ V_4 ] . V_74 ,
F_20 ,
& V_70 , NULL ) ) && V_70 ) {
F_26 ( & V_65 -> V_19 ,
L_7 , V_68 [ V_4 ] . V_74 ) ;
V_3 = V_68 [ V_4 ] . V_69 ;
V_67 -> V_42 = & V_68 [ V_4 ] ;
break;
}
}
V_3 -> V_19 = & V_65 -> V_19 ;
sprintf ( V_71 , L_8 , V_67 -> V_42 -> V_74 ) ;
strcpy ( ( char * ) V_3 -> V_75 [ 2 ] . V_71 , V_71 ) ;
F_27 ( V_3 , V_67 ) ;
V_66 = F_28 ( & V_65 -> V_19 , V_3 ) ;
if ( V_66 ) {
F_3 ( & V_65 -> V_19 ,
L_9 , V_66 ) ;
return V_66 ;
}
F_29 ( V_65 , V_3 ) ;
return V_66 ;
}
