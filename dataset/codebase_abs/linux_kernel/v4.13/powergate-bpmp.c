static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 ,
unsigned int V_6 , T_1 V_7 )
{
struct V_8 V_9 ;
struct V_10 V_11 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_12 = V_13 ;
V_9 . V_6 = V_6 ;
V_9 . V_14 . V_7 = V_7 ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_15 = V_16 ;
V_11 . V_17 . V_18 = & V_9 ;
V_11 . V_17 . V_19 = sizeof( V_9 ) ;
return F_4 ( V_5 , & V_11 ) ;
}
static int F_5 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
struct V_20 V_21 ;
struct V_8 V_9 ;
struct V_10 V_11 ;
int V_22 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_12 = V_23 ;
V_9 . V_6 = V_6 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_15 = V_16 ;
V_11 . V_17 . V_18 = & V_9 ;
V_11 . V_17 . V_19 = sizeof( V_9 ) ;
V_11 . V_24 . V_18 = & V_21 ;
V_11 . V_24 . V_19 = sizeof( V_21 ) ;
V_22 = F_4 ( V_5 , & V_11 ) ;
if ( V_22 < 0 )
return V_25 ;
return V_21 . V_26 . V_7 ;
}
static int F_6 ( struct V_4 * V_5 )
{
struct V_20 V_21 ;
struct V_8 V_9 ;
struct V_10 V_11 ;
int V_22 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_12 = V_27 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_15 = V_16 ;
V_11 . V_17 . V_18 = & V_9 ;
V_11 . V_17 . V_19 = sizeof( V_9 ) ;
V_11 . V_24 . V_18 = & V_21 ;
V_11 . V_24 . V_19 = sizeof( V_21 ) ;
V_22 = F_4 ( V_5 , & V_11 ) ;
if ( V_22 < 0 )
return V_22 ;
return V_21 . V_28 . V_29 ;
}
static char * F_7 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
struct V_20 V_21 ;
struct V_8 V_9 ;
struct V_10 V_11 ;
int V_22 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_12 = V_30 ;
V_9 . V_6 = V_6 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_15 = V_16 ;
V_11 . V_17 . V_18 = & V_9 ;
V_11 . V_17 . V_19 = sizeof( V_9 ) ;
V_11 . V_24 . V_18 = & V_21 ;
V_11 . V_24 . V_19 = sizeof( V_21 ) ;
V_22 = F_4 ( V_5 , & V_11 ) ;
if ( V_22 < 0 )
return NULL ;
return F_8 ( V_21 . V_31 . V_32 , V_33 ) ;
}
static inline bool F_9 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
return F_5 ( V_5 , V_6 ) != V_25 ;
}
static int F_10 ( struct V_2 * V_34 )
{
struct V_1 * V_35 = F_1 ( V_34 ) ;
struct V_4 * V_5 = V_35 -> V_5 ;
return F_3 ( V_5 , V_35 -> V_6 ,
V_36 ) ;
}
static int F_11 ( struct V_2 * V_34 )
{
struct V_1 * V_35 = F_1 ( V_34 ) ;
struct V_4 * V_5 = V_35 -> V_5 ;
return F_3 ( V_5 , V_35 -> V_6 ,
V_25 ) ;
}
static struct V_1 *
F_12 ( struct V_4 * V_5 ,
const struct V_37 * V_38 )
{
struct V_1 * V_35 ;
bool V_39 ;
int V_22 ;
V_39 = ! F_9 ( V_5 , V_38 -> V_6 ) ;
V_35 = F_13 ( V_5 -> V_40 , sizeof( * V_35 ) , V_33 ) ;
if ( ! V_35 )
return F_14 ( - V_41 ) ;
V_35 -> V_6 = V_38 -> V_6 ;
V_35 -> V_5 = V_5 ;
V_35 -> V_3 . V_32 = F_8 ( V_38 -> V_32 , V_33 ) ;
V_35 -> V_3 . V_42 = F_10 ;
V_35 -> V_3 . V_43 = F_11 ;
V_22 = F_15 ( & V_35 -> V_3 , NULL , V_39 ) ;
if ( V_22 < 0 ) {
F_16 ( V_35 -> V_3 . V_32 ) ;
return F_14 ( V_22 ) ;
}
return V_35 ;
}
static void F_17 ( struct V_1 * V_35 )
{
struct V_2 * V_3 = & V_35 -> V_3 ;
struct V_4 * V_5 = V_35 -> V_5 ;
int V_22 ;
V_22 = F_18 ( V_3 ) ;
if ( V_22 < 0 )
F_19 ( V_5 -> V_40 , L_1 ,
V_3 -> V_32 , V_22 ) ;
F_16 ( V_3 -> V_32 ) ;
}
static int
F_20 ( struct V_4 * V_5 ,
struct V_37 * * V_44 )
{
struct V_37 * V_45 ;
unsigned int V_29 , V_6 , V_46 = 0 ;
unsigned int V_47 = 0 ;
int V_22 ;
V_22 = F_6 ( V_5 ) ;
if ( V_22 < 0 )
return V_22 ;
V_29 = V_22 ;
F_21 ( V_5 -> V_40 , L_2 , V_29 ) ;
V_45 = F_22 ( V_29 + 1 , sizeof( * V_45 ) , V_33 ) ;
if ( ! V_45 )
return - V_41 ;
for ( V_6 = 0 ; V_6 <= V_29 ; V_6 ++ ) {
struct V_37 * V_38 = & V_45 [ V_46 ] ;
V_38 -> V_32 = F_7 ( V_5 , V_6 ) ;
if ( ! V_38 -> V_32 || V_38 -> V_32 [ 0 ] == '\0' ) {
V_47 ++ ;
continue;
}
V_38 -> V_6 = V_6 ;
V_46 ++ ;
}
F_21 ( V_5 -> V_40 , L_3 , V_47 ) ;
* V_44 = V_45 ;
return V_46 ;
}
static int F_23 ( struct V_4 * V_5 ,
struct V_37 * V_45 ,
unsigned int V_46 )
{
struct V_48 * V_3 = & V_5 -> V_3 ;
struct V_2 * * V_49 ;
struct V_1 * V_35 ;
unsigned int V_50 ;
int V_22 ;
V_49 = F_22 ( V_46 , sizeof( * V_49 ) , V_33 ) ;
if ( ! V_49 )
return - V_41 ;
for ( V_50 = 0 ; V_50 < V_46 ; V_50 ++ ) {
V_35 = F_12 ( V_5 , & V_45 [ V_50 ] ) ;
if ( F_24 ( V_35 ) ) {
V_22 = F_25 ( V_35 ) ;
goto remove;
}
F_21 ( V_5 -> V_40 , L_4 ,
V_35 -> V_3 . V_32 ) ;
V_49 [ V_50 ] = & V_35 -> V_3 ;
}
V_3 -> V_51 = V_46 ;
V_3 -> V_49 = V_49 ;
return 0 ;
remove:
while ( V_50 -- ) {
V_35 = F_1 ( V_49 [ V_50 ] ) ;
F_17 ( V_35 ) ;
}
F_16 ( V_3 -> V_49 ) ;
return V_22 ;
}
static void F_26 ( struct V_4 * V_5 )
{
struct V_48 * V_3 = & V_5 -> V_3 ;
unsigned int V_50 = V_3 -> V_51 ;
struct V_1 * V_35 ;
while ( V_50 -- ) {
F_21 ( V_5 -> V_40 , L_5 ,
V_3 -> V_49 [ V_50 ] -> V_32 ) ;
V_35 = F_1 ( V_3 -> V_49 [ V_50 ] ) ;
F_17 ( V_35 ) ;
}
}
static struct V_2 *
F_27 ( struct V_52 * V_53 , void * V_18 )
{
struct V_2 * V_34 = F_14 ( - V_54 ) ;
struct V_48 * V_3 = V_18 ;
unsigned int V_50 ;
for ( V_50 = 0 ; V_50 < V_3 -> V_51 ; V_50 ++ ) {
struct V_1 * V_35 ;
V_35 = F_1 ( V_3 -> V_49 [ V_50 ] ) ;
if ( V_35 -> V_6 == V_53 -> args [ 0 ] ) {
V_34 = & V_35 -> V_3 ;
break;
}
}
return V_34 ;
}
int F_28 ( struct V_4 * V_5 )
{
struct V_55 * V_56 = V_5 -> V_40 -> V_57 ;
struct V_37 * V_45 ;
struct V_58 * V_40 = V_5 -> V_40 ;
unsigned int V_46 , V_50 ;
int V_22 ;
V_22 = F_20 ( V_5 , & V_45 ) ;
if ( V_22 < 0 )
return V_22 ;
V_46 = V_22 ;
F_21 ( V_40 , L_6 , V_46 ) ;
V_22 = F_23 ( V_5 , V_45 , V_46 ) ;
if ( V_22 < 0 )
goto free;
V_5 -> V_3 . V_59 = F_27 ;
V_22 = F_29 ( V_56 , & V_5 -> V_3 ) ;
if ( V_22 < 0 ) {
F_19 ( V_40 , L_7 , V_22 ) ;
F_26 ( V_5 ) ;
}
free:
for ( V_50 = 0 ; V_50 < V_46 ; V_50 ++ )
F_16 ( V_45 [ V_50 ] . V_32 ) ;
F_16 ( V_45 ) ;
return V_22 ;
}
