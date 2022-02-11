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
return V_36 ;
}
} else {
V_33 -> V_9 . V_42 = V_43 ;
memcpy ( ( char * ) ( & V_33 -> V_9 . V_44 ) , V_14 ,
sizeof( struct V_45 ) ) ;
}
} else {
F_25 ( & V_8 -> V_37 ) ;
return - V_52 ;
}
F_25 ( & V_8 -> V_37 ) ;
V_46:
F_26 ( & V_33 -> V_49 ) ;
return 0 ;
}
void F_27 ( const struct V_11 * V_12 , const T_1 * V_14 , T_2 V_10 )
{
struct V_15 * V_16 = F_6 ( V_12 ) ;
struct V_1 * V_8 = V_16 -> V_31 ;
struct V_32 * V_33 , * V_34 ;
T_1 * V_9 = ( T_1 * ) V_14 ;
int V_35 ;
int V_36 = - 1 ;
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
F_28 ( & V_33 -> V_37 ) ;
if ( F_29 ( & V_33 -> V_49 ) ) {
F_19 ( & V_33 -> V_48 ) ;
F_20 ( & V_33 -> V_48 ) ;
F_24 ( & V_33 -> V_48 , & V_8 -> V_47 ) ;
F_26 ( & V_8 -> V_50 ) ;
if ( V_10 )
F_11 ( V_12 , ( const struct V_13 * ) V_14 ) ;
}
F_30 ( & V_33 -> V_37 ) ;
F_25 ( & V_8 -> V_37 ) ;
}
static int F_31 ( struct V_11 * V_53 ,
struct V_11 * V_12 )
{
struct V_54 * V_55 = NULL ;
struct V_56 * V_57 ;
int V_36 = 0 ;
V_55 = F_32 ( V_53 ) ;
if ( ! V_55 )
return V_36 ;
F_13 ( & V_55 -> V_37 ) ;
F_14 (ifa, &idev->addr_list, if_list) {
V_36 = F_12 ( V_12 , ( const T_1 * ) V_57 -> V_9 . V_26 , 1 ) ;
if ( V_36 < 0 )
break;
}
F_15 ( & V_55 -> V_37 ) ;
return V_36 ;
}
int F_33 ( struct V_11 * V_12 )
{
struct V_11 * V_53 = NULL ;
int V_58 , V_36 = 0 ;
V_36 = F_31 ( V_12 , V_12 ) ;
if ( V_36 )
return V_36 ;
V_53 = F_34 ( V_12 ) ;
if ( V_53 ) {
V_36 = F_31 ( V_53 , V_12 ) ;
if ( V_36 )
return V_36 ;
}
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ ) {
V_53 = F_35 ( V_12 , F_36 ( V_60 ) , V_58 ) ;
if ( ! V_53 )
continue;
V_36 = F_31 ( V_53 , V_12 ) ;
if ( V_36 )
break;
}
return V_36 ;
}
int F_37 ( struct V_61 * V_62 , void * V_63 )
{
struct V_15 * V_15 = V_62 -> V_64 ;
struct V_1 * V_8 = V_15 -> V_31 ;
struct V_32 * V_33 ;
char V_65 [ 60 ] ;
int V_58 ;
F_13 ( & V_8 -> V_37 ) ;
F_38 ( V_62 , L_1 ) ;
for ( V_58 = 0 ; V_58 < V_8 -> V_5 ; ++ V_58 ) {
F_14 (ce, &ctbl->hash_list[i], list) {
V_65 [ 0 ] = '\0' ;
sprintf ( V_65 , L_2 , & V_33 -> V_9 ) ;
F_39 ( V_62 , L_3 , V_65 ,
F_40 ( & V_33 -> V_49 ) ) ;
}
}
F_39 ( V_62 , L_4 , F_40 ( & V_8 -> V_50 ) ) ;
F_15 ( & V_8 -> V_37 ) ;
return 0 ;
}
struct V_1 * F_41 ( unsigned int V_66 ,
unsigned int V_67 )
{
struct V_32 * V_68 ;
struct V_1 * V_8 ;
unsigned int V_5 ;
int V_58 ;
if ( V_66 >= V_67 )
return NULL ;
V_5 = V_67 - V_66 + 1 ;
if ( V_5 < V_69 )
return NULL ;
V_8 = F_42 ( sizeof( * V_8 ) +
V_5 * sizeof( struct V_70 ) ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_66 = V_66 ;
V_8 -> V_5 = V_5 ;
F_20 ( & V_8 -> V_47 ) ;
F_22 ( & V_8 -> V_50 , V_5 ) ;
F_43 ( & V_8 -> V_37 ) ;
for ( V_58 = 0 ; V_58 < V_8 -> V_5 ; ++ V_58 )
F_20 ( & V_8 -> V_51 [ V_58 ] ) ;
V_68 = F_42 ( V_5 * sizeof( struct V_32 ) ) ;
if ( ! V_68 ) {
F_44 ( V_8 ) ;
return NULL ;
}
V_8 -> V_68 = ( void * ) V_68 ;
for ( V_58 = 0 ; V_58 < V_5 ; V_58 ++ ) {
F_20 ( & V_68 [ V_58 ] . V_48 ) ;
F_24 ( & V_68 [ V_58 ] . V_48 , & V_8 -> V_47 ) ;
}
return V_8 ;
}
void F_45 ( struct V_15 * V_16 )
{
struct V_1 * V_8 = V_16 -> V_31 ;
if ( V_8 ) {
if ( V_8 -> V_68 )
F_44 ( V_8 -> V_68 ) ;
F_44 ( V_8 ) ;
}
}
