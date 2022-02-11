static int F_1 ( struct V_1 * V_2 , int V_3 ,
enum V_4 V_5 , T_1 * V_6 ,
T_1 * V_7 )
{
int V_8 ;
struct V_9 * V_10 = V_2 -> V_10 ;
F_2 ( & V_2 -> V_11 ) ;
V_8 = F_3 ( V_10 ,
V_3 ,
V_5 ,
V_6 , V_7 ,
1000 ) ;
if ( V_8 ) {
if ( V_8 == V_12 && V_5 == V_13 ) {
F_4 ( L_1 ,
V_2 -> V_14 , V_3 , V_5 ) ;
} else {
F_5 ( L_2 ,
V_2 -> V_14 , V_3 , V_5 ,
V_8 ) ;
}
} else {
F_4 ( L_3 ,
V_2 -> V_14 , V_3 , V_5 ) ;
}
return V_8 ;
}
static int F_6 ( struct V_1 * V_2 , int V_3 ,
enum V_4 V_5 , T_1 * V_6 , T_1 * V_7 )
{
int V_8 ;
F_7 ( & V_2 -> V_11 ) ;
V_8 = F_1 ( V_2 , V_3 , V_5 , V_6 , V_7 ) ;
F_8 ( & V_2 -> V_11 ) ;
return V_8 ;
}
struct V_1 * F_9 ( struct V_15 * V_16 )
{
struct V_1 * V_2 ;
V_2 = F_10 ( sizeof( * V_2 ) , V_17 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_16 = V_16 ;
V_2 -> V_10 = F_11 ( V_16 ) ;
F_12 ( & V_2 -> V_11 ) ;
strncpy ( V_2 -> V_14 , F_13 ( V_2 -> V_10 ) ,
sizeof( V_2 -> V_14 ) - 1 ) ;
return V_2 ;
}
void F_14 ( struct V_1 * V_2 )
{
F_15 ( V_2 ) ;
}
void F_16 ( struct V_1 * V_2 , char V_18 [ V_19 ] )
{
F_7 ( & V_2 -> V_11 ) ;
memcpy ( & V_2 -> V_18 , V_18 , sizeof( V_2 -> V_18 ) ) ;
F_8 ( & V_2 -> V_11 ) ;
}
int F_17 ( struct V_1 * V_2 , T_2 V_20 )
{
int V_8 ;
F_7 ( & V_2 -> V_11 ) ;
if ( V_2 -> V_20 == 0 ) {
V_2 -> V_20 = V_20 ;
V_8 = 0 ;
} else {
V_8 = - V_21 ;
}
F_8 ( & V_2 -> V_11 ) ;
return V_8 ;
}
void F_18 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_11 ) ;
V_2 -> V_20 = 0 ;
F_8 ( & V_2 -> V_11 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_11 ) ;
V_2 -> V_22 = 1 ;
F_8 ( & V_2 -> V_11 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_11 ) ;
V_2 -> V_22 = 0 ;
F_8 ( & V_2 -> V_11 ) ;
}
void F_21 ( struct V_1 * V_2 , unsigned int V_23 )
{
F_7 ( & V_2 -> V_11 ) ;
V_2 -> V_23 = V_23 ;
F_8 ( & V_2 -> V_11 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_11 ) ;
if ( ! V_2 -> V_22 )
return - V_24 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_25 * V_25 )
{
F_2 ( & V_2 -> V_11 ) ;
if ( V_25 -> type == V_26 ) {
if ( ! ( V_25 -> V_27 . V_28 . V_29 & V_30 ) )
return - V_31 ;
if ( ! ( V_25 -> V_27 . V_28 . V_29 & V_32 ) )
return - V_33 ;
else if ( V_2 -> V_20 == 0 )
return - V_34 ;
else if ( V_25 -> V_27 . V_28 . V_35 == 0 )
return - V_36 ;
else if ( F_24 ( V_2 -> V_20 ) != V_25 -> V_27 . V_28 . V_37 )
return - V_21 ;
else
return 0 ;
}
return 0 ;
}
static void F_25 ( struct V_38 * V_39 , struct V_25 * V_25 ,
struct V_40 * V_41 )
{
V_39 -> type = V_42 ;
V_39 -> V_43 = sizeof( struct V_25 ) ;
* ( (struct V_25 * ) & V_39 -> V_44 ) = * V_25 ;
V_39 = (struct V_38 * ) ( ( char * ) V_39 + sizeof( struct V_38 ) +
sizeof( struct V_25 ) ) ;
V_39 -> type = V_45 ;
V_39 -> V_43 = sizeof( struct V_40 ) ;
* ( (struct V_40 * ) & V_39 -> V_44 ) = * V_41 ;
}
struct V_46 *
F_26 ( struct V_1 * V_2 , struct V_25 * V_25 ,
struct V_47 * V_48 )
{
struct V_38 * V_39 ;
struct V_15 * V_16 ;
struct V_46 * V_49 ;
T_3 V_6 , V_7 ;
T_3 V_50 ;
T_4 V_51 ;
int V_8 ;
V_16 = V_2 -> V_16 ;
V_50 = ( 2 * sizeof( struct V_38 ) + sizeof( struct V_25 ) +
sizeof( struct V_40 ) ) ;
V_49 = F_10 ( sizeof( * V_49 ) , V_52 ) ;
if ( ! V_49 )
return F_27 ( - V_53 ) ;
V_39 = F_28 ( V_16 , V_50 , & V_51 ) ;
if ( ! V_39 ) {
F_5 ( L_4 ) ;
V_8 = - V_53 ;
goto V_54;
}
F_25 ( V_39 , V_25 , & V_48 -> V_41 ) ;
F_7 ( & V_2 -> V_11 ) ;
V_8 = F_22 ( V_2 ) ;
if ( V_8 ) {
F_5 ( L_5 ,
V_2 -> V_14 , V_8 ) ;
goto V_55;
}
V_8 = F_23 ( V_2 , V_25 ) ;
if ( V_8 ) {
F_5 ( L_6 ,
V_8 ) ;
goto V_55;
}
V_6 = V_51 ;
V_7 = V_50 ;
V_8 = F_1 ( V_2 , V_48 -> V_3 ,
V_56 , & V_6 , & V_7 ) ;
if ( V_8 ) {
F_5 ( L_7 ,
V_2 -> V_14 , V_8 ) ;
V_8 = - V_21 ;
goto V_55;
} else {
F_4 ( L_8 , V_2 -> V_14 , V_6 ) ;
}
V_49 -> V_57 = ( V_58 ) V_6 ;
V_49 -> V_3 = V_48 -> V_3 ;
V_49 -> V_2 = V_2 ;
V_55:
F_8 ( & V_2 -> V_11 ) ;
F_29 ( V_16 , V_50 , V_39 , V_51 ) ;
if ( ! V_8 )
return V_49 ;
V_54:
F_15 ( V_49 ) ;
return F_27 ( V_8 ) ;
}
int F_30 ( struct V_46 * V_49 )
{
int V_8 ;
T_1 V_6 , V_7 ;
V_6 = V_49 -> V_57 ;
V_8 = F_6 ( V_49 -> V_2 , V_49 -> V_3 ,
V_13 , & V_6 , & V_7 ) ;
if ( V_8 ) {
if ( V_8 == V_12 ) {
F_4 ( L_9 ,
V_49 -> V_57 , V_49 -> V_3 ,
V_49 -> V_2 -> V_14 , V_8 ) ;
} else {
F_5 ( L_10 ,
V_49 -> V_2 -> V_14 , V_49 -> V_3 ,
V_49 -> V_57 , V_8 ) ;
}
V_8 = 0 ;
} else {
F_4 ( L_11 ,
V_49 -> V_2 -> V_14 , V_49 -> V_3 ,
V_49 -> V_57 ) ;
}
F_15 ( V_49 ) ;
return V_8 ;
}
int F_31 ( struct V_1 * V_2 , int V_3 , int V_59 )
{
int V_8 ;
struct V_9 * V_60 ;
T_1 V_6 , V_7 ;
V_60 = V_2 -> V_10 ;
V_6 = V_59 ;
V_7 = V_61 ;
V_8 = F_6 ( V_2 , V_3 , V_62 ,
& V_6 , & V_7 ) ;
if ( V_8 ) {
F_5 ( L_12 ,
F_13 ( V_60 ) ,
V_3 ,
V_59 ,
V_8 ) ;
} else {
F_4 ( L_13 ,
F_13 ( V_60 ) ,
V_3 , V_59 ) ;
}
return V_8 ;
}
int F_32 ( struct V_1 * V_2 , int V_3 , int V_59 )
{
int V_8 ;
T_1 V_6 , V_7 ;
struct V_9 * V_60 ;
V_60 = V_2 -> V_10 ;
V_6 = V_59 ;
V_7 = V_61 ;
V_8 = F_6 ( V_2 , V_3 , V_63 ,
& V_6 , & V_7 ) ;
if ( V_8 ) {
F_5 ( L_14 ,
F_13 ( V_60 ) ,
V_3 ,
V_59 ,
V_8 ) ;
} else {
F_4 ( L_15 ,
F_13 ( V_60 ) ,
V_3 ,
V_59 ) ;
}
return V_8 ;
}
