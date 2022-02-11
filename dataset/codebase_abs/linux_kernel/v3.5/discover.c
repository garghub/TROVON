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
struct V_20 V_21 ;
F_11 ( V_18 , V_15 ) ;
F_12 ( & V_21 , V_19 , sizeof( V_19 ) ) ;
F_13 ( & V_21 , V_17 ) ;
F_14 ( & V_21 ) ;
F_15 ( L_1 ,
V_18 , V_19 , V_4 -> V_22 ) ;
}
void F_16 ( struct V_1 * V_5 , struct V_3 * V_4 )
{
struct V_23 * V_24 ;
struct V_25 * V_26 ;
struct V_16 V_17 ;
struct V_1 * V_27 ;
struct V_7 * V_8 = F_3 ( V_5 ) ;
T_1 V_28 = F_17 ( V_8 ) ;
T_1 V_29 = F_18 ( V_8 ) ;
T_1 V_30 = F_19 ( V_8 ) ;
T_1 type = F_20 ( V_8 ) ;
T_1 V_31 = F_21 ( V_8 ) ;
int V_32 ;
int V_33 ;
V_17 . V_34 = 1 ;
V_4 -> V_12 -> V_35 ( & V_17 , F_9 ( V_8 ) ) ;
F_22 ( V_5 ) ;
if ( V_30 != V_11 )
return;
if ( V_17 . V_34 )
return;
if ( ! F_23 ( V_28 ) )
return;
if ( ! F_24 ( V_29 ) )
return;
if ( V_29 == V_36 ) {
if ( memcmp ( & V_17 , & V_4 -> V_14 , sizeof( V_17 ) ) )
F_10 ( V_4 , V_36 , & V_17 ) ;
return;
}
if ( ! F_25 ( V_28 , V_36 ) )
return;
if ( ! F_25 ( V_4 -> V_37 -> V_38 , V_29 ) )
return;
V_24 = F_26 ( V_29 ) ;
if ( ! V_24 ) {
V_24 = F_27 ( V_29 ) ;
if ( ! V_24 )
return;
}
F_28 ( V_24 ) ;
V_26 = V_24 -> V_39 [ V_4 -> V_40 ] ;
V_32 = ( V_26 != NULL ) &&
memcmp ( & V_26 -> V_17 , & V_17 , sizeof( V_17 ) ) ;
if ( V_31 != V_24 -> V_31 ) {
if ( V_24 -> V_41 == 0 ) {
struct V_25 * V_42 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
V_42 = V_24 -> V_39 [ V_43 ] ;
if ( V_42 ) {
memset ( & V_42 -> V_17 , 0 ,
sizeof( V_17 ) ) ;
F_29 ( V_42 ) ;
}
}
V_32 = ( V_26 != NULL ) ;
} else if ( F_30 ( V_26 ) && ! V_32 ) {
} else {
F_10 ( V_4 , V_29 , & V_17 ) ;
F_31 ( V_24 ) ;
return;
}
V_24 -> V_31 = V_31 ;
}
if ( V_32 ) {
if ( F_30 ( V_26 ) ) {
F_10 ( V_4 , V_29 , & V_17 ) ;
F_31 ( V_24 ) ;
return;
} else {
memcpy ( & V_26 -> V_17 , & V_17 ,
sizeof( V_17 ) ) ;
F_29 ( V_26 ) ;
}
}
if ( ! V_26 ) {
V_26 = F_32 ( V_24 , V_4 , & V_17 ) ;
if ( ! V_26 ) {
F_31 ( V_24 ) ;
return;
}
}
V_33 = F_33 ( V_26 ) ;
if ( ( type == V_45 ) && ! V_33 && ! V_4 -> V_46 ) {
V_27 = F_1 ( V_47 , V_29 , V_4 ) ;
if ( V_27 ) {
V_4 -> V_12 -> V_48 ( V_27 , V_4 , & V_17 ) ;
F_22 ( V_27 ) ;
}
}
F_31 ( V_24 ) ;
}
static void F_34 ( struct V_49 * V_50 )
{
if ( ! V_50 -> V_51 ) {
if ( ( V_50 -> V_52 == V_53 ) ||
( V_50 -> V_52 > V_54 ) ) {
V_50 -> V_52 = V_55 ;
F_35 ( & V_50 -> V_56 , V_50 -> V_52 ) ;
}
}
}
void F_36 ( struct V_49 * V_50 )
{
V_50 -> V_51 ++ ;
}
void F_37 ( struct V_49 * V_50 )
{
V_50 -> V_51 -- ;
F_34 ( V_50 ) ;
}
static void F_38 ( struct V_49 * V_50 )
{
if ( ! V_50 -> V_57 -> V_46 )
F_39 ( V_50 -> V_57 , V_50 -> V_5 , & V_50 -> V_28 ) ;
}
static void F_40 ( struct V_49 * V_50 )
{
int V_58 ;
F_41 ( & V_50 -> V_57 -> V_59 ) ;
if ( V_23 ( V_50 -> V_38 ) && V_50 -> V_51 ) {
V_50 -> V_52 = V_53 ;
goto exit;
}
F_38 ( V_50 ) ;
V_50 -> V_52 *= 2 ;
if ( V_50 -> V_51 )
V_58 = V_60 ;
else
V_58 = V_54 ;
if ( V_50 -> V_52 > V_58 )
V_50 -> V_52 = V_58 ;
F_35 ( & V_50 -> V_56 , V_50 -> V_52 ) ;
exit:
F_42 ( & V_50 -> V_57 -> V_59 ) ;
}
int F_43 ( struct V_3 * V_4 ,
struct V_16 * V_28 , T_1 V_2 )
{
struct V_49 * V_50 ;
V_50 = F_44 ( sizeof( * V_50 ) , V_61 ) ;
if ( ! V_50 )
return - V_62 ;
V_50 -> V_5 = F_1 ( V_45 , V_2 , V_4 ) ;
if ( ! V_50 -> V_5 ) {
F_45 ( V_50 ) ;
return - V_63 ;
}
memcpy ( & V_50 -> V_28 , V_28 , sizeof( * V_28 ) ) ;
V_50 -> V_57 = V_4 ;
V_50 -> V_38 = V_2 ;
V_50 -> V_51 = 0 ;
V_50 -> V_52 = V_55 ;
F_46 ( & V_50 -> V_56 , ( V_64 ) F_40 , ( unsigned long ) V_50 ) ;
F_35 ( & V_50 -> V_56 , V_50 -> V_52 ) ;
V_4 -> V_37 = V_50 ;
F_38 ( V_50 ) ;
return 0 ;
}
void F_47 ( struct V_49 * V_50 )
{
F_48 ( & V_50 -> V_56 ) ;
F_49 ( & V_50 -> V_56 ) ;
F_22 ( V_50 -> V_5 ) ;
F_45 ( V_50 ) ;
}
