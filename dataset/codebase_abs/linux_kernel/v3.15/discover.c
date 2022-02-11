static struct V_1 * F_1 ( T_1 type , struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_5 ) ;
struct V_6 * V_7 ;
T_1 V_8 = V_3 -> V_9 ;
if ( V_4 ) {
V_7 = F_3 ( V_4 ) ;
F_4 ( V_7 , V_10 , type , V_5 , V_8 ) ;
F_5 ( V_7 , 1 ) ;
F_6 ( V_7 , V_11 ) ;
F_7 ( V_7 , V_8 ) ;
F_8 ( V_7 , V_12 ) ;
V_3 -> V_13 -> V_14 ( & V_3 -> V_15 , F_9 ( V_7 ) ) ;
}
return V_4 ;
}
static void F_10 ( struct V_2 * V_3 , T_1 V_16 ,
struct V_17 * V_18 )
{
char V_19 [ 16 ] ;
char V_20 [ 64 ] ;
F_11 ( V_19 , V_16 ) ;
F_12 ( V_20 , sizeof( V_20 ) ,
V_18 ) ;
F_13 ( L_1 , V_19 ,
V_20 , V_3 -> V_21 ) ;
}
void F_14 ( struct V_1 * V_4 , struct V_2 * V_3 )
{
struct V_22 * V_23 ;
struct V_24 * V_25 ;
struct V_17 V_18 ;
struct V_1 * V_26 ;
struct V_6 * V_7 = F_3 ( V_4 ) ;
T_1 V_27 = F_15 ( V_7 ) ;
T_1 V_28 = F_16 ( V_7 ) ;
T_1 V_29 = F_17 ( V_7 ) ;
T_1 type = F_18 ( V_7 ) ;
T_1 V_30 = F_19 ( V_7 ) ;
int V_31 ;
int V_32 ;
V_18 . V_33 = 1 ;
V_3 -> V_13 -> V_34 ( V_3 , & V_18 , F_9 ( V_7 ) ) ;
F_20 ( V_4 ) ;
if ( V_29 != V_12 )
return;
if ( V_18 . V_33 )
return;
if ( ! F_21 ( V_27 ) )
return;
if ( ! F_22 ( V_28 ) )
return;
if ( V_28 == V_35 ) {
if ( memcmp ( & V_18 , & V_3 -> V_15 , sizeof( V_18 ) ) )
F_10 ( V_3 , V_35 , & V_18 ) ;
return;
}
if ( ! F_23 ( V_27 , V_35 ) )
return;
if ( ! F_23 ( V_3 -> V_9 , V_28 ) )
return;
V_23 = F_24 ( V_28 ) ;
if ( ! V_23 ) {
V_23 = F_25 ( V_28 ) ;
if ( ! V_23 )
return;
}
F_26 ( V_23 ) ;
V_25 = V_23 -> V_36 [ V_3 -> V_37 ] ;
V_31 = ( V_25 != NULL ) &&
memcmp ( & V_25 -> V_18 , & V_18 , sizeof( V_18 ) ) ;
if ( V_30 != V_23 -> V_30 ) {
if ( V_23 -> V_38 == 0 ) {
struct V_24 * V_39 ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_41 ; V_40 ++ ) {
V_39 = V_23 -> V_36 [ V_40 ] ;
if ( V_39 ) {
memset ( & V_39 -> V_18 , 0 ,
sizeof( V_18 ) ) ;
F_27 ( V_39 ) ;
}
}
V_31 = ( V_25 != NULL ) ;
} else if ( F_28 ( V_25 ) && ! V_31 ) {
} else {
F_10 ( V_3 , V_28 , & V_18 ) ;
F_29 ( V_23 ) ;
return;
}
V_23 -> V_30 = V_30 ;
}
if ( V_31 ) {
if ( F_28 ( V_25 ) ) {
F_10 ( V_3 , V_28 , & V_18 ) ;
F_29 ( V_23 ) ;
return;
} else {
memcpy ( & V_25 -> V_18 , & V_18 ,
sizeof( V_18 ) ) ;
F_27 ( V_25 ) ;
}
}
if ( ! V_25 ) {
V_25 = F_30 ( V_23 , V_3 , & V_18 ) ;
if ( ! V_25 ) {
F_29 ( V_23 ) ;
return;
}
}
V_32 = F_31 ( V_25 ) ;
if ( ( type == V_42 ) && ! V_32 ) {
V_26 = F_1 ( V_43 , V_3 ) ;
if ( V_26 ) {
F_32 ( V_3 , V_26 , & V_18 ) ;
F_20 ( V_26 ) ;
}
}
F_29 ( V_23 ) ;
}
static void F_33 ( struct V_44 * V_45 )
{
if ( ! V_45 -> V_46 ) {
if ( ( V_45 -> V_47 == V_48 ) ||
( V_45 -> V_47 > V_49 ) ) {
V_45 -> V_47 = V_50 ;
F_34 ( & V_45 -> V_51 , V_45 -> V_47 ) ;
}
}
}
void F_35 ( struct V_44 * V_45 )
{
F_36 ( & V_45 -> V_52 ) ;
V_45 -> V_46 ++ ;
F_37 ( & V_45 -> V_52 ) ;
}
void F_38 ( struct V_44 * V_45 )
{
F_36 ( & V_45 -> V_52 ) ;
V_45 -> V_46 -- ;
F_33 ( V_45 ) ;
F_37 ( & V_45 -> V_52 ) ;
}
static void F_39 ( struct V_44 * V_45 )
{
int V_53 ;
F_36 ( & V_45 -> V_52 ) ;
if ( V_22 ( V_45 -> V_54 -> V_9 ) && V_45 -> V_46 ) {
V_45 -> V_47 = V_48 ;
goto exit;
}
F_32 ( V_45 -> V_54 , V_45 -> V_4 , & V_45 -> V_27 ) ;
V_45 -> V_47 *= 2 ;
if ( V_45 -> V_46 )
V_53 = V_55 ;
else
V_53 = V_49 ;
if ( V_45 -> V_47 > V_53 )
V_45 -> V_47 = V_53 ;
F_34 ( & V_45 -> V_51 , V_45 -> V_47 ) ;
exit:
F_37 ( & V_45 -> V_52 ) ;
}
int F_40 ( struct V_2 * V_3 , struct V_17 * V_27 )
{
struct V_44 * V_45 ;
V_45 = F_41 ( sizeof( * V_45 ) , V_56 ) ;
if ( ! V_45 )
return - V_57 ;
V_45 -> V_4 = F_1 ( V_42 , V_3 ) ;
if ( ! V_45 -> V_4 ) {
F_42 ( V_45 ) ;
return - V_58 ;
}
memcpy ( & V_45 -> V_27 , V_27 , sizeof( * V_27 ) ) ;
V_45 -> V_54 = V_3 ;
V_45 -> V_46 = 0 ;
V_45 -> V_47 = V_50 ;
F_43 ( & V_45 -> V_52 ) ;
F_44 ( & V_45 -> V_51 , ( V_59 ) F_39 , ( unsigned long ) V_45 ) ;
F_34 ( & V_45 -> V_51 , V_45 -> V_47 ) ;
V_3 -> V_60 = V_45 ;
F_32 ( V_45 -> V_54 , V_45 -> V_4 , & V_45 -> V_27 ) ;
return 0 ;
}
void F_45 ( struct V_44 * V_45 )
{
F_46 ( & V_45 -> V_51 ) ;
F_47 ( & V_45 -> V_51 ) ;
F_20 ( V_45 -> V_4 ) ;
F_42 ( V_45 ) ;
}
