static T_1 F_1 ( struct V_1 * V_1 ,
const char T_2 * V_2 , T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
char V_8 [ 16 ] ;
long V_9 , V_10 ;
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
if ( F_2 ( & V_8 , V_2 , F_3 ( T_3 , sizeof( V_8 ) - 1 , V_3 ) ) )
return - V_11 ;
V_10 = F_4 ( V_8 , 10 , & V_9 ) ;
if ( V_10 )
return V_10 ;
V_6 -> V_12 . V_13 = V_9 ;
if ( V_6 -> V_12 . V_13 ) {
F_5 ( V_6 ) ;
F_6 ( & V_6 -> V_14 . V_15 ) ;
}
return V_3 ;
}
static T_1 F_7 ( struct V_1 * V_1 , char T_2 * V_16 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
char V_8 [ 16 ] ;
int V_10 ;
V_10 = snprintf ( V_8 , sizeof( V_8 ) - 1 , L_1 ,
V_6 -> V_12 . V_13 ) ;
return F_8 ( V_16 , V_3 , V_4 , V_8 , V_10 ) ;
}
static T_1 F_9 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
char V_8 [ 16 ] ;
long V_9 , V_10 ;
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
if ( F_2 ( & V_8 , V_2 , F_3 ( T_3 , sizeof( V_8 ) - 1 , V_3 ) ) )
return - V_11 ;
V_10 = F_4 ( V_8 , 10 , & V_9 ) ;
if ( V_10 )
return V_10 ;
V_6 -> V_12 . V_17 = V_9 ;
if ( V_6 -> V_12 . V_17 ) {
F_5 ( V_6 ) ;
F_6 ( & V_6 -> V_14 . V_15 ) ;
}
return V_3 ;
}
static T_1 F_10 ( struct V_1 * V_1 , char T_2 * V_16 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
char V_8 [ 16 ] ;
int V_10 ;
V_10 = snprintf ( V_8 , sizeof( V_8 ) - 1 , L_1 , V_6 -> V_12 . V_17 ) ;
return F_8 ( V_16 , V_3 , V_4 , V_8 , V_10 ) ;
}
static T_1 F_11 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
char V_8 [ 16 ] ;
long V_9 , V_10 ;
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
if ( F_2 ( & V_8 , V_2 , F_3 ( T_3 , sizeof( V_8 ) - 1 , V_3 ) ) )
return - V_11 ;
V_10 = F_4 ( V_8 , 10 , & V_9 ) ;
if ( V_10 )
return V_10 ;
V_6 -> V_12 . V_18 = V_9 ;
if ( V_6 -> V_12 . V_18 ) {
F_5 ( V_6 ) ;
F_6 ( & V_6 -> V_14 . V_15 ) ;
}
return V_3 ;
}
static T_1 F_12 ( struct V_1 * V_1 , char T_2 * V_16 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
char V_8 [ 16 ] ;
int V_10 ;
V_10 = snprintf ( V_8 , sizeof( V_8 ) - 1 , L_1 , V_6 -> V_12 . V_18 ) ;
return F_8 ( V_16 , V_3 , V_4 , V_8 , V_10 ) ;
}
void F_13 ( struct V_19 * V_20 )
{
struct V_5 * V_6 = F_14 ( V_20 ) ;
struct V_21 * V_22 ;
if ( ! V_20 -> V_23 )
return;
V_22 = F_15 ( sizeof( * V_22 ) , V_24 ) ;
V_6 -> V_25 = V_22 ;
if ( ! V_22 ) {
F_16 ( L_2 ) ;
return;
}
V_22 -> V_26 = F_17 ( L_3 , V_20 -> V_23 ) ;
F_18 ( L_4 , 0644 , V_22 -> V_26 ,
& V_6 -> V_12 . V_27 ) ;
F_19 ( L_5 , 0644 , V_22 -> V_26 ,
V_6 , & V_28 ) ;
F_20 ( L_6 , 0644 , V_22 -> V_26 ,
& V_6 -> V_12 . V_29 ) ;
F_18 ( L_7 , 0644 , V_22 -> V_26 ,
& V_6 -> V_12 . V_30 ) ;
F_19 ( L_8 , 0644 , V_22 -> V_26 ,
V_6 , & V_31 ) ;
F_19 ( L_9 , 0644 , V_22 -> V_26 ,
V_6 , & V_32 ) ;
V_22 -> V_33 = F_17 ( L_10 , V_20 -> V_23 ) ;
F_18 ( L_11 , 0444 , V_22 -> V_33 ,
& V_6 -> V_34 -> V_27 ) ;
F_18 ( L_12 , 0444 , V_22 -> V_33 ,
& V_6 -> V_34 -> V_35 ) ;
F_18 ( L_13 , 0444 , V_22 -> V_33 ,
& V_6 -> V_34 -> V_36 ) ;
F_18 ( L_14 , 0444 , V_22 -> V_33 ,
& V_6 -> V_12 . V_37 ) ;
}
void F_21 ( struct V_19 * V_20 )
{
struct V_5 * V_6 = F_14 ( V_20 ) ;
struct V_21 * V_22 = V_6 -> V_25 ;
if ( ! V_22 )
return;
F_22 ( V_22 -> V_26 ) ;
F_22 ( V_22 -> V_33 ) ;
F_23 ( V_22 ) ;
}
