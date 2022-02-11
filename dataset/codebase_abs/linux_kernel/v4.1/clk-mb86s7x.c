static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 V_7 ;
int V_8 ;
V_7 . V_9 = sizeof( V_7 ) ;
V_7 . V_10 = V_5 -> V_10 ;
V_7 . V_11 = V_5 -> V_11 ;
V_7 . V_12 = V_5 -> V_12 ;
V_7 . V_3 = V_3 ;
if ( V_7 . V_12 == 8 )
return V_3 ? 0 : - V_13 ;
F_3 ( L_1 ,
V_14 , __LINE__ , V_7 . V_10 ,
V_7 . V_11 , V_7 . V_12 , V_7 . V_3 ) ;
V_8 = F_4 ( V_15 ,
& V_7 , sizeof( V_7 ) ) ;
if ( V_8 < 0 ) {
F_5 ( L_2 , V_14 , __LINE__ ) ;
return V_8 ;
}
F_3 ( L_3 ,
V_14 , __LINE__ , V_7 . V_10 ,
V_7 . V_11 , V_7 . V_12 , V_7 . V_3 ) ;
if ( V_7 . V_3 != V_3 )
V_8 = - V_13 ;
else
V_8 = 0 ;
return V_8 ;
}
static int F_6 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , 1 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0 ) ;
}
static int
F_8 ( struct V_1 * V_2 , int V_16 , unsigned long * V_17 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 V_7 ;
int V_18 , V_8 ;
V_7 . V_9 = sizeof( V_7 ) ;
V_7 . V_10 = V_5 -> V_10 ;
V_7 . V_11 = V_5 -> V_11 ;
V_7 . V_12 = V_5 -> V_12 ;
V_7 . V_19 = * V_17 ;
if ( V_16 ) {
V_18 = V_20 ;
F_3 ( L_4 ,
V_14 , __LINE__ , V_7 . V_10 ,
V_7 . V_11 , V_7 . V_12 , V_7 . V_19 ) ;
} else {
V_18 = V_21 ;
F_3 ( L_5 ,
V_14 , __LINE__ , V_7 . V_10 ,
V_7 . V_11 , V_7 . V_12 ) ;
}
V_8 = F_4 ( V_18 , & V_7 , sizeof( V_7 ) ) ;
if ( V_8 < 0 ) {
F_5 ( L_2 , V_14 , __LINE__ ) ;
return V_8 ;
}
if ( V_16 )
F_3 ( L_6 ,
V_14 , __LINE__ , V_7 . V_10 ,
V_7 . V_11 , V_7 . V_12 , V_7 . V_19 ) ;
else
F_3 ( L_7 ,
V_14 , __LINE__ , V_7 . V_10 ,
V_7 . V_11 , V_7 . V_12 , V_7 . V_19 ) ;
* V_17 = V_7 . V_19 ;
return 0 ;
}
static unsigned long
F_9 ( struct V_1 * V_2 , unsigned long V_22 )
{
unsigned long V_17 ;
F_8 ( V_2 , 0 , & V_17 ) ;
return V_17 ;
}
static long
F_10 ( struct V_1 * V_2 ,
unsigned long V_17 , unsigned long * V_23 )
{
return V_17 ;
}
static int
F_11 ( struct V_1 * V_2 ,
unsigned long V_17 , unsigned long V_22 )
{
return F_8 ( V_2 , 1 , & V_17 ) ;
}
static struct V_24 * F_12 ( struct V_25 * V_26 , void * V_27 )
{
struct V_28 * V_29 = V_27 ;
struct V_30 V_31 ;
T_1 V_10 , V_11 , V_12 ;
struct V_4 * V_5 ;
struct V_24 * V_24 ;
char V_32 [ 20 ] ;
if ( V_26 -> V_33 != 3 )
return F_13 ( - V_13 ) ;
V_10 = V_26 -> args [ 0 ] ;
V_11 = V_26 -> args [ 1 ] ;
V_12 = V_26 -> args [ 2 ] ;
if ( V_12 > 7 )
snprintf ( V_32 , 20 , L_8 , V_10 , V_11 ) ;
else
snprintf ( V_32 , 20 , L_9 , V_10 , V_11 , V_12 ) ;
F_14 ( & V_29 -> V_34 ) ;
V_24 = F_15 ( V_32 ) ;
if ( V_24 ) {
F_16 ( & V_29 -> V_34 ) ;
return V_24 ;
}
V_5 = F_17 ( sizeof( * V_5 ) , V_35 ) ;
if ( ! V_5 ) {
F_16 ( & V_29 -> V_34 ) ;
return F_13 ( - V_36 ) ;
}
V_31 . V_37 = V_32 ;
V_31 . V_38 = 0 ;
V_31 . V_39 = & V_40 ;
V_31 . V_41 = V_42 ;
V_5 -> V_2 . V_31 = & V_31 ;
V_5 -> V_10 = V_10 ;
V_5 -> V_11 = V_11 ;
V_5 -> V_12 = V_12 ;
V_24 = F_18 ( NULL , & V_5 -> V_2 ) ;
if ( F_19 ( V_24 ) )
F_5 ( L_10 , V_14 , __LINE__ ) ;
else
F_3 ( L_11 , V_32 ) ;
F_20 ( V_24 , V_32 , NULL ) ;
F_16 ( & V_29 -> V_34 ) ;
return V_24 ;
}
static void T_2 F_21 ( struct V_43 * V_44 )
{
struct V_28 * V_29 ;
V_29 = F_17 ( sizeof( * V_29 ) , V_35 ) ;
if ( ! V_29 )
return;
F_22 ( & V_29 -> V_34 ) ;
F_23 ( V_44 , F_12 , V_29 ) ;
}
static void F_24 ( struct V_1 * V_2 , unsigned long * V_17 , int V_45 )
{
struct V_46 * V_47 = F_25 ( V_2 ) ;
struct V_48 V_7 ;
int V_18 , V_8 ;
V_7 . V_9 = sizeof( V_7 ) ;
V_7 . V_49 = 0 ;
V_7 . V_50 = V_47 -> V_51 ;
V_7 . V_52 = 0 ;
V_7 . V_19 = * V_17 ;
if ( V_45 )
V_18 = V_53 ;
else
V_18 = V_54 ;
F_3 ( L_12 ,
V_14 , __LINE__ , V_7 . V_49 ,
V_7 . V_50 , V_7 . V_52 , V_7 . V_19 ) ;
V_8 = F_4 ( V_18 , & V_7 , sizeof( V_7 ) ) ;
if ( V_8 < 0 ) {
F_5 ( L_2 , V_14 , __LINE__ ) ;
return;
}
F_3 ( L_13 ,
V_14 , __LINE__ , V_7 . V_49 ,
V_7 . V_50 , V_7 . V_52 , V_7 . V_19 ) ;
* V_17 = V_7 . V_19 ;
}
static unsigned long
F_26 ( struct V_1 * V_2 , unsigned long V_55 )
{
unsigned long V_17 ;
F_24 ( V_2 , & V_17 , 1 ) ;
return V_17 ;
}
static long
F_27 ( struct V_1 * V_2 , unsigned long V_17 ,
unsigned long * V_55 )
{
return V_17 ;
}
static int
F_28 ( struct V_1 * V_2 , unsigned long V_17 ,
unsigned long V_55 )
{
unsigned long V_56 = V_17 ;
F_24 ( V_2 , & V_56 , 0 ) ;
return ( V_56 == V_17 ) ? 0 : - V_13 ;
}
struct V_24 * F_29 ( struct V_57 * V_58 )
{
struct V_30 V_31 ;
struct V_46 * V_47 ;
V_47 = F_17 ( sizeof( * V_47 ) , V_35 ) ;
if ( ! V_47 )
return F_13 ( - V_36 ) ;
V_47 -> V_2 . V_31 = & V_31 ;
V_47 -> V_51 = F_30 ( V_58 -> V_59 ) ;
V_31 . V_37 = F_31 ( V_58 ) ;
V_31 . V_39 = & V_60 ;
V_31 . V_41 = V_42 | V_61 ;
V_31 . V_38 = 0 ;
return F_32 ( V_58 , & V_47 -> V_2 ) ;
}
static int F_33 ( void )
{
int V_62 , V_8 = - V_63 ;
struct V_43 * V_64 ;
struct V_24 * V_24 ;
V_64 = F_34 ( NULL , NULL , L_14 ) ;
if ( ! V_64 || ! F_35 ( V_64 ) )
goto exit;
F_36 (cpu) {
struct V_57 * V_58 = F_37 ( V_62 ) ;
if ( ! V_58 ) {
F_5 ( L_15 , V_62 ) ;
continue;
}
V_24 = F_29 ( V_58 ) ;
if ( F_19 ( V_24 ) ) {
F_5 ( L_16 , V_62 ) ;
continue;
}
if ( F_20 ( V_24 , NULL , F_31 ( V_58 ) ) ) {
F_5 ( L_17 , V_62 ) ;
continue;
}
F_3 ( L_18 , F_31 ( V_58 ) ) ;
}
V_8 = 0 ;
F_38 ( L_19 , - 1 , NULL , 0 ) ;
exit:
F_39 ( V_64 ) ;
return V_8 ;
}
