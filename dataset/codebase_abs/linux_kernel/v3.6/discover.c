static struct V_1 * F_1 ( T_1 type ,
T_1 V_2 ,
struct V_3 * V_4 )
{
struct V_1 * V_5 = F_2 ( V_6 ) ;
struct V_7 * V_8 ;
if ( V_5 ) {
V_8 = F_3 ( V_5 ) ;
F_4 ( V_8 , V_9 , type , V_6 , V_2 ) ;
F_5 ( V_8 , 1 ) ;
F_6 ( V_8 , V_10 ) ;
F_7 ( V_8 , V_2 ) ;
F_8 ( V_8 , V_11 ) ;
V_4 -> V_12 -> V_13 ( & V_4 -> V_14 , F_9 ( V_8 ) ) ;
}
return V_5 ;
}
static void F_10 ( struct V_3 * V_4 , T_1 V_15 ,
struct V_16 * V_17 )
{
char V_18 [ 16 ] ;
char V_19 [ 64 ] ;
F_11 ( V_18 , V_15 ) ;
F_12 ( V_19 , sizeof( V_19 ) ,
V_17 ) ;
F_13 ( L_1 , V_18 ,
V_19 , V_4 -> V_20 ) ;
}
void F_14 ( struct V_1 * V_5 , struct V_3 * V_4 )
{
struct V_21 * V_22 ;
struct V_23 * V_24 ;
struct V_16 V_17 ;
struct V_1 * V_25 ;
struct V_7 * V_8 = F_3 ( V_5 ) ;
T_1 V_26 = F_15 ( V_8 ) ;
T_1 V_27 = F_16 ( V_8 ) ;
T_1 V_28 = F_17 ( V_8 ) ;
T_1 type = F_18 ( V_8 ) ;
T_1 V_29 = F_19 ( V_8 ) ;
int V_30 ;
int V_31 ;
V_17 . V_32 = 1 ;
V_4 -> V_12 -> V_33 ( & V_17 , F_9 ( V_8 ) ) ;
F_20 ( V_5 ) ;
if ( V_28 != V_11 )
return;
if ( V_17 . V_32 )
return;
if ( ! F_21 ( V_26 ) )
return;
if ( ! F_22 ( V_27 ) )
return;
if ( V_27 == V_34 ) {
if ( memcmp ( & V_17 , & V_4 -> V_14 , sizeof( V_17 ) ) )
F_10 ( V_4 , V_34 , & V_17 ) ;
return;
}
if ( ! F_23 ( V_26 , V_34 ) )
return;
if ( ! F_23 ( V_4 -> V_35 -> V_36 , V_27 ) )
return;
V_22 = F_24 ( V_27 ) ;
if ( ! V_22 ) {
V_22 = F_25 ( V_27 ) ;
if ( ! V_22 )
return;
}
F_26 ( V_22 ) ;
V_24 = V_22 -> V_37 [ V_4 -> V_38 ] ;
V_30 = ( V_24 != NULL ) &&
memcmp ( & V_24 -> V_17 , & V_17 , sizeof( V_17 ) ) ;
if ( V_29 != V_22 -> V_29 ) {
if ( V_22 -> V_39 == 0 ) {
struct V_23 * V_40 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_42 ; V_41 ++ ) {
V_40 = V_22 -> V_37 [ V_41 ] ;
if ( V_40 ) {
memset ( & V_40 -> V_17 , 0 ,
sizeof( V_17 ) ) ;
F_27 ( V_40 ) ;
}
}
V_30 = ( V_24 != NULL ) ;
} else if ( F_28 ( V_24 ) && ! V_30 ) {
} else {
F_10 ( V_4 , V_27 , & V_17 ) ;
F_29 ( V_22 ) ;
return;
}
V_22 -> V_29 = V_29 ;
}
if ( V_30 ) {
if ( F_28 ( V_24 ) ) {
F_10 ( V_4 , V_27 , & V_17 ) ;
F_29 ( V_22 ) ;
return;
} else {
memcpy ( & V_24 -> V_17 , & V_17 ,
sizeof( V_17 ) ) ;
F_27 ( V_24 ) ;
}
}
if ( ! V_24 ) {
V_24 = F_30 ( V_22 , V_4 , & V_17 ) ;
if ( ! V_24 ) {
F_29 ( V_22 ) ;
return;
}
}
V_31 = F_31 ( V_24 ) ;
if ( ( type == V_43 ) && ! V_31 && ! V_4 -> V_44 ) {
V_25 = F_1 ( V_45 , V_27 , V_4 ) ;
if ( V_25 ) {
V_4 -> V_12 -> V_46 ( V_25 , V_4 , & V_17 ) ;
F_20 ( V_25 ) ;
}
}
F_29 ( V_22 ) ;
}
static void F_32 ( struct V_47 * V_48 )
{
if ( ! V_48 -> V_49 ) {
if ( ( V_48 -> V_50 == V_51 ) ||
( V_48 -> V_50 > V_52 ) ) {
V_48 -> V_50 = V_53 ;
F_33 ( & V_48 -> V_54 , V_48 -> V_50 ) ;
}
}
}
void F_34 ( struct V_47 * V_48 )
{
V_48 -> V_49 ++ ;
}
void F_35 ( struct V_47 * V_48 )
{
V_48 -> V_49 -- ;
F_32 ( V_48 ) ;
}
static void F_36 ( struct V_47 * V_48 )
{
if ( ! V_48 -> V_55 -> V_44 )
F_37 ( V_48 -> V_55 , V_48 -> V_5 , & V_48 -> V_26 ) ;
}
static void F_38 ( struct V_47 * V_48 )
{
int V_56 ;
F_39 ( & V_48 -> V_55 -> V_57 ) ;
if ( V_21 ( V_48 -> V_36 ) && V_48 -> V_49 ) {
V_48 -> V_50 = V_51 ;
goto exit;
}
F_36 ( V_48 ) ;
V_48 -> V_50 *= 2 ;
if ( V_48 -> V_49 )
V_56 = V_58 ;
else
V_56 = V_52 ;
if ( V_48 -> V_50 > V_56 )
V_48 -> V_50 = V_56 ;
F_33 ( & V_48 -> V_54 , V_48 -> V_50 ) ;
exit:
F_40 ( & V_48 -> V_55 -> V_57 ) ;
}
int F_41 ( struct V_3 * V_4 ,
struct V_16 * V_26 , T_1 V_2 )
{
struct V_47 * V_48 ;
V_48 = F_42 ( sizeof( * V_48 ) , V_59 ) ;
if ( ! V_48 )
return - V_60 ;
V_48 -> V_5 = F_1 ( V_43 , V_2 , V_4 ) ;
if ( ! V_48 -> V_5 ) {
F_43 ( V_48 ) ;
return - V_61 ;
}
memcpy ( & V_48 -> V_26 , V_26 , sizeof( * V_26 ) ) ;
V_48 -> V_55 = V_4 ;
V_48 -> V_36 = V_2 ;
V_48 -> V_49 = 0 ;
V_48 -> V_50 = V_53 ;
F_44 ( & V_48 -> V_54 , ( V_62 ) F_38 , ( unsigned long ) V_48 ) ;
F_33 ( & V_48 -> V_54 , V_48 -> V_50 ) ;
V_4 -> V_35 = V_48 ;
F_36 ( V_48 ) ;
return 0 ;
}
void F_45 ( struct V_47 * V_48 )
{
F_46 ( & V_48 -> V_54 ) ;
F_47 ( & V_48 -> V_54 ) ;
F_20 ( V_48 -> V_5 ) ;
F_43 ( V_48 ) ;
}
