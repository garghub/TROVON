static inline unsigned int F_1 ( struct V_1 * V_2 , const T_1 * V_3 )
{
unsigned int V_4 = V_2 -> V_5 / 2 ;
return F_2 ( * V_3 , 0 ) % V_4 ;
}
static inline unsigned int F_3 ( struct V_1 * V_6 , const T_1 * V_3 )
{
unsigned int V_4 = V_6 -> V_5 / 2 ;
T_1 V_7 = V_3 [ 0 ] ^ V_3 [ 1 ] ^ V_3 [ 2 ] ^ V_3 [ 3 ] ;
return V_4 +
( F_2 ( V_7 , 0 ) % V_4 ) ;
}
static unsigned int F_4 ( struct V_1 * V_8 , const T_1 * V_9 ,
T_2 V_10 )
{
return V_10 ? F_3 ( V_8 , V_9 ) :
F_1 ( V_8 , V_9 ) ;
}
static int F_5 ( const struct V_11 * V_12 ,
const struct V_13 * V_14 )
{
struct V_15 * V_16 = F_6 ( V_12 ) ;
struct V_17 V_2 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_18 = F_7 ( F_8 ( V_19 ) |
V_20 | V_21 ) ;
V_2 . V_22 = F_7 ( V_23 | F_9 ( V_2 ) ) ;
* ( V_24 * ) & V_2 . V_25 = * ( V_24 * ) ( V_14 -> V_26 ) ;
* ( V_24 * ) & V_2 . V_27 = * ( V_24 * ) ( V_14 -> V_26 + 8 ) ;
return F_10 ( V_16 , V_16 -> V_28 , & V_2 , sizeof( V_2 ) , & V_2 , false ) ;
}
static int F_11 ( const struct V_11 * V_12 ,
const struct V_13 * V_14 )
{
struct V_15 * V_16 = F_6 ( V_12 ) ;
struct V_17 V_2 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_18 = F_7 ( F_8 ( V_19 ) |
V_20 | V_29 ) ;
V_2 . V_22 = F_7 ( V_30 | F_9 ( V_2 ) ) ;
* ( V_24 * ) & V_2 . V_25 = * ( V_24 * ) ( V_14 -> V_26 ) ;
* ( V_24 * ) & V_2 . V_27 = * ( V_24 * ) ( V_14 -> V_26 + 8 ) ;
return F_10 ( V_16 , V_16 -> V_28 , & V_2 , sizeof( V_2 ) , & V_2 , false ) ;
}
int F_12 ( const struct V_11 * V_12 , const T_1 * V_14 , T_2 V_10 )
{
struct V_15 * V_16 = F_6 ( V_12 ) ;
struct V_1 * V_8 = V_16 -> V_31 ;
struct V_32 * V_33 , * V_34 ;
T_1 * V_9 = ( T_1 * ) V_14 ;
int V_35 ;
int V_36 = - 1 ;
if ( ! V_8 )
return 0 ;
V_35 = F_4 ( V_8 , V_9 , V_10 ) ;
F_13 ( & V_8 -> V_37 ) ;
F_14 (cte, &ctbl->hash_list[hash], list) {
if ( V_34 -> V_38 . V_39 == V_40 && V_10 )
V_36 = memcmp ( V_14 , V_34 -> V_38 . V_41 . V_26 ,
sizeof( struct V_13 ) ) ;
else if ( V_34 -> V_9 . V_42 == V_43 && ! V_10 )
V_36 = memcmp ( V_14 , ( char * ) ( & V_34 -> V_9 . V_44 ) ,
sizeof( struct V_45 ) ) ;
if ( ! V_36 ) {
V_33 = V_34 ;
F_15 ( & V_8 -> V_37 ) ;
goto V_46;
}
}
F_15 ( & V_8 -> V_37 ) ;
F_16 ( & V_8 -> V_37 ) ;
if ( ! F_17 ( & V_8 -> V_47 ) ) {
V_33 = F_18 ( & V_8 -> V_47 ,
struct V_32 , V_48 ) ;
F_19 ( & V_33 -> V_48 ) ;
F_20 ( & V_33 -> V_48 ) ;
F_21 ( & V_33 -> V_37 ) ;
F_22 ( & V_33 -> V_49 , 0 ) ;
F_23 ( & V_8 -> V_50 ) ;
F_24 ( & V_33 -> V_48 , & V_8 -> V_51 [ V_35 ] ) ;
if ( V_10 ) {
V_33 -> V_38 . V_39 = V_40 ;
memcpy ( V_33 -> V_38 . V_41 . V_26 ,
V_14 , sizeof( struct V_13 ) ) ;
V_36 = F_5 ( V_12 , ( const struct V_13 * ) V_14 ) ;
if ( V_36 ) {
F_25 ( & V_8 -> V_37 ) ;
F_26 ( V_16 -> V_52 ,
L_1
L_2
L_3 ,
V_36 , V_33 -> V_38 . V_41 . V_26 ) ;
return V_36 ;
}
} else {
V_33 -> V_9 . V_42 = V_43 ;
memcpy ( ( char * ) ( & V_33 -> V_9 . V_44 ) , V_14 ,
sizeof( struct V_45 ) ) ;
}
} else {
F_25 ( & V_8 -> V_37 ) ;
F_27 ( V_16 -> V_52 , L_4
L_5 ,
( void * ) V_14 ) ;
return - V_53 ;
}
F_25 ( & V_8 -> V_37 ) ;
V_46:
F_28 ( & V_33 -> V_49 ) ;
return 0 ;
}
void F_29 ( const struct V_11 * V_12 , const T_1 * V_14 , T_2 V_10 )
{
struct V_15 * V_16 = F_6 ( V_12 ) ;
struct V_1 * V_8 = V_16 -> V_31 ;
struct V_32 * V_33 , * V_34 ;
T_1 * V_9 = ( T_1 * ) V_14 ;
int V_35 ;
int V_36 = - 1 ;
if ( ! V_8 )
return;
V_35 = F_4 ( V_8 , V_9 , V_10 ) ;
F_13 ( & V_8 -> V_37 ) ;
F_14 (cte, &ctbl->hash_list[hash], list) {
if ( V_34 -> V_38 . V_39 == V_40 && V_10 )
V_36 = memcmp ( V_14 , V_34 -> V_38 . V_41 . V_26 ,
sizeof( struct V_13 ) ) ;
else if ( V_34 -> V_9 . V_42 == V_43 && ! V_10 )
V_36 = memcmp ( V_14 , ( char * ) ( & V_34 -> V_9 . V_44 ) ,
sizeof( struct V_45 ) ) ;
if ( ! V_36 ) {
V_33 = V_34 ;
F_15 ( & V_8 -> V_37 ) ;
goto V_46;
}
}
F_15 ( & V_8 -> V_37 ) ;
return;
V_46:
F_16 ( & V_8 -> V_37 ) ;
F_30 ( & V_33 -> V_37 ) ;
if ( F_31 ( & V_33 -> V_49 ) ) {
F_19 ( & V_33 -> V_48 ) ;
F_20 ( & V_33 -> V_48 ) ;
F_24 ( & V_33 -> V_48 , & V_8 -> V_47 ) ;
F_28 ( & V_8 -> V_50 ) ;
if ( V_10 )
F_11 ( V_12 , ( const struct V_13 * ) V_14 ) ;
}
F_32 ( & V_33 -> V_37 ) ;
F_25 ( & V_8 -> V_37 ) ;
}
static int F_33 ( struct V_11 * V_54 ,
struct V_11 * V_12 )
{
struct V_55 * V_56 = NULL ;
struct V_57 * V_58 ;
int V_36 = 0 ;
V_56 = F_34 ( V_54 ) ;
if ( ! V_56 )
return V_36 ;
F_13 ( & V_56 -> V_37 ) ;
F_14 (ifa, &idev->addr_list, if_list) {
V_36 = F_12 ( V_12 , ( const T_1 * ) V_58 -> V_9 . V_26 , 1 ) ;
if ( V_36 < 0 )
break;
}
F_15 ( & V_56 -> V_37 ) ;
return V_36 ;
}
int F_35 ( struct V_11 * V_12 )
{
struct V_11 * V_54 = NULL ;
int V_59 , V_36 = 0 ;
V_36 = F_33 ( V_12 , V_12 ) ;
if ( V_36 )
return V_36 ;
V_54 = F_36 ( V_12 ) ;
if ( V_54 ) {
V_36 = F_33 ( V_54 , V_12 ) ;
if ( V_36 )
return V_36 ;
}
for ( V_59 = 0 ; V_59 < V_60 ; V_59 ++ ) {
V_54 = F_37 ( V_12 , F_38 ( V_61 ) , V_59 ) ;
if ( ! V_54 )
continue;
V_36 = F_33 ( V_54 , V_12 ) ;
if ( V_36 )
break;
}
return V_36 ;
}
int F_39 ( struct V_62 * V_63 , void * V_64 )
{
struct V_15 * V_15 = V_63 -> V_65 ;
struct V_1 * V_8 = V_15 -> V_31 ;
struct V_32 * V_33 ;
char V_66 [ 60 ] ;
int V_59 ;
F_13 ( & V_8 -> V_37 ) ;
F_40 ( V_63 , L_6 ) ;
for ( V_59 = 0 ; V_59 < V_8 -> V_5 ; ++ V_59 ) {
F_14 (ce, &ctbl->hash_list[i], list) {
V_66 [ 0 ] = '\0' ;
sprintf ( V_66 , L_7 , & V_33 -> V_9 ) ;
F_41 ( V_63 , L_8 , V_66 ,
F_42 ( & V_33 -> V_49 ) ) ;
}
}
F_41 ( V_63 , L_9 , F_42 ( & V_8 -> V_50 ) ) ;
F_15 ( & V_8 -> V_37 ) ;
return 0 ;
}
struct V_1 * F_43 ( unsigned int V_67 ,
unsigned int V_68 )
{
struct V_32 * V_69 ;
struct V_1 * V_8 ;
unsigned int V_5 ;
int V_59 ;
if ( V_67 >= V_68 )
return NULL ;
V_5 = V_68 - V_67 + 1 ;
if ( V_5 < V_70 )
return NULL ;
V_8 = F_44 ( sizeof( * V_8 ) +
V_5 * sizeof( struct V_71 ) , V_72 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_67 = V_67 ;
V_8 -> V_5 = V_5 ;
F_20 ( & V_8 -> V_47 ) ;
F_22 ( & V_8 -> V_50 , V_5 ) ;
F_45 ( & V_8 -> V_37 ) ;
for ( V_59 = 0 ; V_59 < V_8 -> V_5 ; ++ V_59 )
F_20 ( & V_8 -> V_51 [ V_59 ] ) ;
V_69 = F_44 ( V_5 * sizeof( struct V_32 ) , V_72 ) ;
if ( ! V_69 ) {
F_46 ( V_8 ) ;
return NULL ;
}
V_8 -> V_69 = ( void * ) V_69 ;
for ( V_59 = 0 ; V_59 < V_5 ; V_59 ++ ) {
F_20 ( & V_69 [ V_59 ] . V_48 ) ;
F_24 ( & V_69 [ V_59 ] . V_48 , & V_8 -> V_47 ) ;
}
return V_8 ;
}
void F_47 ( struct V_15 * V_16 )
{
struct V_1 * V_8 = V_16 -> V_31 ;
if ( V_8 ) {
if ( V_8 -> V_69 )
F_46 ( V_8 -> V_69 ) ;
F_46 ( V_8 ) ;
}
}
