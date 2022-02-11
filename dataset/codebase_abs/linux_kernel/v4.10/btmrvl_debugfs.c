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
static T_1 F_13 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
char V_8 [ 16 ] ;
bool V_9 ;
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
if ( F_2 ( & V_8 , V_2 , F_3 ( T_3 , sizeof( V_8 ) - 1 , V_3 ) ) )
return - V_11 ;
if ( F_14 ( V_8 , & V_9 ) )
return - V_19 ;
if ( ! V_9 )
return - V_19 ;
F_15 ( V_6 ) ;
return V_3 ;
}
void F_16 ( struct V_20 * V_21 )
{
struct V_5 * V_6 = F_17 ( V_21 ) ;
struct V_22 * V_23 ;
if ( ! V_21 -> V_24 )
return;
V_23 = F_18 ( sizeof( * V_23 ) , V_25 ) ;
V_6 -> V_26 = V_23 ;
if ( ! V_23 ) {
F_19 ( L_2 ) ;
return;
}
V_23 -> V_27 = F_20 ( L_3 , V_21 -> V_24 ) ;
F_21 ( L_4 , 0644 , V_23 -> V_27 ,
& V_6 -> V_12 . V_28 ) ;
F_22 ( L_5 , 0644 , V_23 -> V_27 ,
V_6 , & V_29 ) ;
F_23 ( L_6 , 0644 , V_23 -> V_27 ,
& V_6 -> V_12 . V_30 ) ;
F_21 ( L_7 , 0644 , V_23 -> V_27 ,
& V_6 -> V_12 . V_31 ) ;
F_22 ( L_8 , 0644 , V_23 -> V_27 ,
V_6 , & V_32 ) ;
F_22 ( L_9 , 0644 , V_23 -> V_27 ,
V_6 , & V_33 ) ;
F_22 ( L_10 , 0200 , V_23 -> V_27 ,
V_6 , & V_34 ) ;
V_23 -> V_35 = F_20 ( L_11 , V_21 -> V_24 ) ;
F_21 ( L_12 , 0444 , V_23 -> V_35 ,
& V_6 -> V_36 -> V_28 ) ;
F_21 ( L_13 , 0444 , V_23 -> V_35 ,
& V_6 -> V_36 -> V_37 ) ;
F_21 ( L_14 , 0444 , V_23 -> V_35 ,
& V_6 -> V_36 -> V_38 ) ;
F_21 ( L_15 , 0444 , V_23 -> V_35 ,
& V_6 -> V_12 . V_39 ) ;
}
void F_24 ( struct V_20 * V_21 )
{
struct V_5 * V_6 = F_17 ( V_21 ) ;
struct V_22 * V_23 = V_6 -> V_26 ;
if ( ! V_23 )
return;
F_25 ( V_23 -> V_27 ) ;
F_25 ( V_23 -> V_35 ) ;
F_26 ( V_23 ) ;
}
