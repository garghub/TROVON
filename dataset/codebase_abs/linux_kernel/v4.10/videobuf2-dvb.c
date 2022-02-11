static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
F_2 ( & V_5 -> V_6 , F_3 ( V_2 , 0 ) ,
F_4 ( V_2 , 0 ) ) ;
return 0 ;
}
static int F_5 ( struct V_7 * V_8 )
{
struct V_9 * V_6 = V_8 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_3 ;
int V_10 = 0 ;
if ( ! V_6 -> V_11 . V_12 )
return - V_13 ;
F_6 ( & V_5 -> V_14 ) ;
V_5 -> V_15 ++ ;
if ( ! V_5 -> V_16 . V_17 ) {
V_10 = F_7 ( & V_5 -> V_16 , F_1 , V_5 , V_5 -> V_18 ) ;
if ( V_10 )
V_5 -> V_15 -- ;
}
if ( ! V_10 )
V_10 = V_5 -> V_15 ;
F_8 ( & V_5 -> V_14 ) ;
return V_10 ;
}
static int F_9 ( struct V_7 * V_8 )
{
struct V_9 * V_6 = V_8 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_3 ;
int V_19 = 0 ;
F_6 ( & V_5 -> V_14 ) ;
V_5 -> V_15 -- ;
if ( 0 == V_5 -> V_15 )
V_19 = F_10 ( & V_5 -> V_16 ) ;
F_8 ( & V_5 -> V_14 ) ;
return V_19 ;
}
static int F_11 ( struct V_20 * V_21 ,
struct V_22 * V_22 ,
void * V_23 ,
struct V_24 * V_24 ,
struct V_25 * V_26 ,
char * V_27 ,
short * V_28 ,
int V_29 )
{
int V_30 ;
F_12 ( & V_21 -> V_14 ) ;
V_30 = F_13 ( & V_21 -> V_31 , V_27 , V_22 ,
V_24 , V_28 ) ;
if ( V_30 < 0 ) {
F_14 ( L_1 ,
V_27 , V_30 ) ;
}
V_21 -> V_31 . V_3 = V_23 ;
V_21 -> V_31 . V_29 = V_29 ;
#ifdef F_15
if ( V_26 )
V_21 -> V_31 . V_26 = V_26 ;
#endif
return V_30 ;
}
static int F_16 ( struct V_32 * V_31 ,
struct V_4 * V_5 )
{
int V_30 ;
V_30 = F_17 ( V_31 , V_5 -> V_12 ) ;
if ( V_30 < 0 ) {
F_14 ( L_2 ,
V_5 -> V_18 , V_30 ) ;
goto V_33;
}
V_5 -> V_6 . V_11 . V_34 =
V_35 | V_36 |
V_37 ;
V_5 -> V_6 . V_3 = V_5 ;
V_5 -> V_6 . V_38 = 256 ;
V_5 -> V_6 . V_39 = 256 ;
V_5 -> V_6 . V_40 = F_5 ;
V_5 -> V_6 . V_41 = F_9 ;
V_30 = F_18 ( & V_5 -> V_6 ) ;
if ( V_30 < 0 ) {
F_14 ( L_3 ,
V_5 -> V_18 , V_30 ) ;
goto V_42;
}
V_5 -> V_43 . V_38 = 256 ;
V_5 -> V_43 . V_6 = & V_5 -> V_6 . V_11 ;
V_5 -> V_43 . V_34 = 0 ;
V_30 = F_19 ( & V_5 -> V_43 , V_31 ) ;
if ( V_30 < 0 ) {
F_14 ( L_4 ,
V_5 -> V_18 , V_30 ) ;
goto V_44;
}
V_5 -> V_45 . V_46 = V_47 ;
V_30 = V_5 -> V_6 . V_11 . V_48 ( & V_5 -> V_6 . V_11 , & V_5 -> V_45 ) ;
if ( V_30 < 0 ) {
F_14 ( L_5 ,
V_5 -> V_18 , V_30 ) ;
goto V_49;
}
V_5 -> V_50 . V_46 = V_51 ;
V_30 = V_5 -> V_6 . V_11 . V_48 ( & V_5 -> V_6 . V_11 , & V_5 -> V_50 ) ;
if ( V_30 < 0 ) {
F_14 ( L_6 ,
V_5 -> V_18 , V_30 ) ;
goto V_52;
}
V_30 = V_5 -> V_6 . V_11 . V_53 ( & V_5 -> V_6 . V_11 , & V_5 -> V_45 ) ;
if ( V_30 < 0 ) {
F_14 ( L_7 ,
V_5 -> V_18 , V_30 ) ;
goto V_54;
}
V_30 = F_20 ( V_31 , & V_5 -> V_55 , & V_5 -> V_6 . V_11 ) ;
if ( V_30 < 0 ) {
F_14 ( L_8 ,
V_5 -> V_18 , V_30 ) ;
goto V_54;
}
return 0 ;
V_54:
V_5 -> V_6 . V_11 . V_56 ( & V_5 -> V_6 . V_11 , & V_5 -> V_50 ) ;
V_52:
V_5 -> V_6 . V_11 . V_56 ( & V_5 -> V_6 . V_11 , & V_5 -> V_45 ) ;
V_49:
F_21 ( & V_5 -> V_43 ) ;
V_44:
F_22 ( & V_5 -> V_6 ) ;
V_42:
F_23 ( V_5 -> V_12 ) ;
V_33:
F_24 ( V_5 -> V_12 ) ;
V_5 -> V_12 = NULL ;
return V_30 ;
}
int F_25 ( struct V_20 * V_57 ,
struct V_22 * V_22 ,
void * V_23 ,
struct V_24 * V_24 ,
struct V_25 * V_26 ,
short * V_28 ,
int V_29 )
{
struct V_58 * V_59 , * V_60 ;
struct V_61 * V_21 ;
int V_62 ;
V_21 = F_26 ( V_57 , 1 ) ;
if ( ! V_21 ) {
F_14 ( L_9 ) ;
return - V_13 ;
}
V_62 = F_11 ( V_57 , V_22 , V_23 , V_24 , V_26 ,
V_21 -> V_5 . V_18 , V_28 , V_29 ) ;
if ( V_62 < 0 ) {
F_14 ( L_10 , V_62 ) ;
return V_62 ;
}
F_6 ( & V_57 -> V_14 ) ;
F_27 (list, q, &f->felist) {
V_21 = F_28 ( V_59 , struct V_61 , V_63 ) ;
V_62 = F_16 ( & V_57 -> V_31 , & V_21 -> V_5 ) ;
if ( V_62 < 0 ) {
F_14 ( L_11 ,
V_21 -> V_5 . V_18 , V_62 ) ;
goto V_19;
}
V_62 = F_29 ( & V_57 -> V_31 , false ) ;
if ( V_62 < 0 )
goto V_19;
}
F_8 ( & V_57 -> V_14 ) ;
return 0 ;
V_19:
F_8 ( & V_57 -> V_14 ) ;
F_30 ( V_57 ) ;
return V_62 ;
}
void F_30 ( struct V_20 * V_57 )
{
F_31 ( V_57 ) ;
F_32 ( & V_57 -> V_31 ) ;
}
struct V_61 * F_26 (
struct V_20 * V_57 , int V_64 )
{
struct V_58 * V_59 , * V_60 ;
struct V_61 * V_21 , * V_65 = NULL ;
F_6 ( & V_57 -> V_14 ) ;
F_27 (list, q, &f->felist) {
V_21 = F_28 ( V_59 , struct V_61 , V_63 ) ;
if ( V_21 -> V_64 == V_64 ) {
V_65 = V_21 ;
break;
}
}
F_8 ( & V_57 -> V_14 ) ;
return V_65 ;
}
int F_33 ( struct V_20 * V_57 ,
struct V_66 * V_67 )
{
struct V_58 * V_59 , * V_60 ;
struct V_61 * V_21 = NULL ;
int V_65 = 0 ;
F_6 ( & V_57 -> V_14 ) ;
F_27 (list, q, &f->felist) {
V_21 = F_28 ( V_59 , struct V_61 , V_63 ) ;
if ( V_21 -> V_5 . V_12 == V_67 ) {
V_65 = V_21 -> V_64 ;
break;
}
}
F_8 ( & V_57 -> V_14 ) ;
return V_65 ;
}
struct V_61 * F_34 (
struct V_20 * V_57 , int V_64 )
{
struct V_61 * V_21 ;
V_21 = F_35 ( sizeof( struct V_61 ) , V_68 ) ;
if ( V_21 == NULL )
return NULL ;
V_21 -> V_64 = V_64 ;
F_12 ( & V_21 -> V_5 . V_14 ) ;
F_6 ( & V_57 -> V_14 ) ;
F_36 ( & V_21 -> V_63 , & V_57 -> V_63 ) ;
F_8 ( & V_57 -> V_14 ) ;
return V_21 ;
}
void F_31 ( struct V_20 * V_57 )
{
struct V_58 * V_59 , * V_60 ;
struct V_61 * V_21 ;
F_6 ( & V_57 -> V_14 ) ;
F_27 (list, q, &f->felist) {
V_21 = F_28 ( V_59 , struct V_61 , V_63 ) ;
if ( V_21 -> V_5 . V_55 . V_69 ) {
F_37 ( & V_21 -> V_5 . V_55 ) ;
V_21 -> V_5 . V_6 . V_11 . V_56 ( & V_21 -> V_5 . V_6 . V_11 ,
& V_21 -> V_5 . V_50 ) ;
V_21 -> V_5 . V_6 . V_11 . V_56 ( & V_21 -> V_5 . V_6 . V_11 ,
& V_21 -> V_5 . V_45 ) ;
F_21 ( & V_21 -> V_5 . V_43 ) ;
F_22 ( & V_21 -> V_5 . V_6 ) ;
F_23 ( V_21 -> V_5 . V_12 ) ;
}
if ( V_21 -> V_5 . V_12 )
F_24 ( V_21 -> V_5 . V_12 ) ;
F_38 ( V_59 ) ;
F_39 ( V_21 ) ;
}
F_8 ( & V_57 -> V_14 ) ;
}
