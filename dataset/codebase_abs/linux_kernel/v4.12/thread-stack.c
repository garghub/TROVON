static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 V_5 , V_6 ;
V_6 = V_2 -> V_5 + V_7 ;
V_5 = V_6 * sizeof( struct V_3 ) ;
V_4 = realloc ( V_2 -> V_8 , V_5 ) ;
if ( ! V_4 )
return - V_9 ;
V_2 -> V_8 = V_4 ;
V_2 -> V_5 = V_6 ;
return 0 ;
}
static struct V_1 * F_2 ( struct V_10 * V_10 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 ;
V_2 = F_3 ( sizeof( struct V_1 ) ) ;
if ( ! V_2 )
return NULL ;
if ( F_1 ( V_2 ) ) {
free ( V_2 ) ;
return NULL ;
}
if ( V_10 -> V_13 && V_10 -> V_13 -> V_14 )
V_2 -> V_15 = F_4 ( V_10 -> V_13 -> V_14 ) ;
else
V_2 -> V_15 = 1ULL << 63 ;
V_2 -> V_12 = V_12 ;
return V_2 ;
}
static int F_5 ( struct V_1 * V_2 , T_2 V_16 )
{
int V_17 = 0 ;
if ( V_2 -> V_18 == V_2 -> V_5 ) {
V_17 = F_1 ( V_2 ) ;
if ( V_17 ) {
F_6 ( L_1 ) ;
V_2 -> V_18 = 0 ;
}
}
V_2 -> V_8 [ V_2 -> V_18 ++ ] . V_16 = V_16 ;
return V_17 ;
}
static void F_7 ( struct V_1 * V_2 , T_2 V_16 )
{
T_1 V_19 ;
for ( V_19 = V_2 -> V_18 ; V_19 ; ) {
if ( V_2 -> V_8 [ -- V_19 ] . V_16 == V_16 ) {
V_2 -> V_18 = V_19 ;
return;
}
}
}
static bool F_8 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_18 )
return false ;
return V_2 -> V_8 [ V_2 -> V_18 - 1 ] . V_20 -> V_21 ;
}
static int F_9 ( struct V_10 * V_10 ,
struct V_1 * V_2 , T_1 V_22 ,
T_2 V_23 , T_2 V_24 , bool V_25 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_3 * V_26 ;
struct V_27 V_28 = {
. V_10 = V_10 ,
. V_29 = V_2 -> V_29 ,
. V_30 = 0 ,
} ;
V_26 = & V_2 -> V_8 [ V_22 ] ;
V_28 . V_20 = V_26 -> V_20 ;
V_28 . V_31 = V_26 -> V_23 ;
V_28 . V_32 = V_23 ;
V_28 . V_33 = V_2 -> V_33 - V_26 -> V_33 ;
V_28 . V_34 = V_26 -> V_24 ;
V_28 . V_35 = V_24 ;
if ( V_26 -> V_36 )
V_28 . V_37 |= V_38 ;
if ( V_25 )
V_28 . V_37 |= V_39 ;
return V_12 -> V_40 ( & V_28 , V_12 -> V_41 ) ;
}
static int F_10 ( struct V_10 * V_10 , struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
int V_17 ;
if ( ! V_12 ) {
V_2 -> V_18 = 0 ;
return 0 ;
}
while ( V_2 -> V_18 ) {
V_17 = F_9 ( V_10 , V_2 , -- V_2 -> V_18 ,
V_2 -> V_42 , 0 , true ) ;
if ( V_17 ) {
F_11 ( L_2 ) ;
V_2 -> V_18 = 0 ;
return V_17 ;
}
}
return 0 ;
}
int F_12 ( struct V_10 * V_10 )
{
if ( V_10 -> V_2 )
return F_10 ( V_10 , V_10 -> V_2 ) ;
return 0 ;
}
int F_13 ( struct V_10 * V_10 , T_3 V_37 , T_2 V_43 ,
T_2 V_44 , T_4 V_45 , T_2 V_46 )
{
if ( ! V_10 )
return - V_47 ;
if ( ! V_10 -> V_2 ) {
V_10 -> V_2 = F_2 ( V_10 , NULL ) ;
if ( ! V_10 -> V_2 ) {
F_6 ( L_3 ) ;
return - V_9 ;
}
V_10 -> V_2 -> V_46 = V_46 ;
}
if ( V_46 != V_10 -> V_2 -> V_46 ) {
if ( V_10 -> V_2 -> V_46 )
F_10 ( V_10 , V_10 -> V_2 ) ;
V_10 -> V_2 -> V_46 = V_46 ;
}
if ( V_10 -> V_2 -> V_12 )
return 0 ;
if ( V_37 & V_48 ) {
T_2 V_16 ;
if ( ! V_44 )
return 0 ;
V_16 = V_43 + V_45 ;
if ( V_16 == V_44 )
return 0 ;
return F_5 ( V_10 -> V_2 , V_16 ) ;
} else if ( V_37 & V_49 ) {
if ( ! V_43 )
return 0 ;
F_7 ( V_10 -> V_2 , V_44 ) ;
}
return 0 ;
}
void F_14 ( struct V_10 * V_10 , T_2 V_46 )
{
if ( ! V_10 || ! V_10 -> V_2 )
return;
if ( V_46 != V_10 -> V_2 -> V_46 ) {
if ( V_10 -> V_2 -> V_46 )
F_10 ( V_10 , V_10 -> V_2 ) ;
V_10 -> V_2 -> V_46 = V_46 ;
}
}
void F_15 ( struct V_10 * V_10 )
{
if ( V_10 -> V_2 ) {
F_10 ( V_10 , V_10 -> V_2 ) ;
F_16 ( & V_10 -> V_2 -> V_8 ) ;
F_16 ( & V_10 -> V_2 ) ;
}
}
void F_17 ( struct V_10 * V_10 , struct V_50 * V_51 ,
T_1 V_5 , T_2 V_52 )
{
T_1 V_19 ;
if ( ! V_10 || ! V_10 -> V_2 )
V_51 -> V_53 = 1 ;
else
V_51 -> V_53 = F_18 ( V_5 , V_10 -> V_2 -> V_18 + 1 ) ;
V_51 -> V_54 [ 0 ] = V_52 ;
for ( V_19 = 1 ; V_19 < V_51 -> V_53 ; V_19 ++ )
V_51 -> V_54 [ V_19 ] = V_10 -> V_2 -> V_8 [ V_10 -> V_2 -> V_18 - V_19 ] . V_16 ;
}
struct V_11 *
F_19 ( int (* V_40)( struct V_27 * V_28 , void * V_41 ) ,
void * V_41 )
{
struct V_11 * V_12 ;
V_12 = F_3 ( sizeof( struct V_11 ) ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_55 = F_20 () ;
if ( ! V_12 -> V_55 )
goto V_56;
V_12 -> V_40 = V_40 ;
V_12 -> V_41 = V_41 ;
return V_12 ;
V_56:
free ( V_12 ) ;
return NULL ;
}
void F_21 ( struct V_11 * V_12 )
{
if ( V_12 ) {
F_22 ( V_12 -> V_55 ) ;
free ( V_12 ) ;
}
}
static int F_23 ( struct V_1 * V_2 , T_2 V_16 ,
T_2 V_23 , T_2 V_24 , struct V_57 * V_20 ,
bool V_36 )
{
struct V_3 * V_26 ;
int V_17 ;
if ( V_2 -> V_18 == V_2 -> V_5 ) {
V_17 = F_1 ( V_2 ) ;
if ( V_17 )
return V_17 ;
}
V_26 = & V_2 -> V_8 [ V_2 -> V_18 ++ ] ;
V_26 -> V_16 = V_16 ;
V_26 -> V_23 = V_23 ;
V_26 -> V_24 = V_24 ;
V_26 -> V_33 = V_2 -> V_33 ;
V_26 -> V_20 = V_20 ;
V_26 -> V_36 = V_36 ;
return 0 ;
}
static int F_24 ( struct V_10 * V_10 , struct V_1 * V_2 ,
T_2 V_16 , T_2 V_23 , T_2 V_24 ,
struct V_58 * V_59 )
{
int V_17 ;
if ( ! V_2 -> V_18 )
return 1 ;
if ( V_2 -> V_18 == 1 ) {
struct V_3 * V_26 = & V_2 -> V_8 [ 0 ] ;
if ( V_26 -> V_20 -> V_59 == V_59 )
return F_9 ( V_10 , V_2 , -- V_2 -> V_18 ,
V_23 , V_24 , false ) ;
}
if ( V_2 -> V_8 [ V_2 -> V_18 - 1 ] . V_16 == V_16 ) {
return F_9 ( V_10 , V_2 , -- V_2 -> V_18 ,
V_23 , V_24 , false ) ;
} else {
T_1 V_19 = V_2 -> V_18 - 1 ;
while ( V_19 -- ) {
if ( V_2 -> V_8 [ V_19 ] . V_16 != V_16 )
continue;
V_19 += 1 ;
while ( V_2 -> V_18 > V_19 ) {
V_17 = F_9 ( V_10 , V_2 ,
-- V_2 -> V_18 ,
V_23 , V_24 ,
true ) ;
if ( V_17 )
return V_17 ;
}
return F_9 ( V_10 , V_2 , -- V_2 -> V_18 ,
V_23 , V_24 , false ) ;
}
}
return 1 ;
}
static int F_25 ( struct V_10 * V_10 , struct V_1 * V_2 ,
struct V_60 * V_61 ,
struct V_62 * V_63 ,
struct V_62 * V_64 , T_2 V_24 )
{
struct V_65 * V_55 = V_2 -> V_12 -> V_55 ;
struct V_57 * V_20 ;
struct V_58 * V_59 ;
T_2 V_52 ;
if ( V_61 -> V_52 ) {
V_52 = V_61 -> V_52 ;
V_59 = V_63 -> V_59 ;
} else if ( V_61 -> V_66 ) {
V_52 = V_61 -> V_66 ;
V_59 = V_64 -> V_59 ;
} else {
return 0 ;
}
V_20 = F_26 ( V_55 , & V_55 -> V_57 , V_59 , V_52 ,
V_2 -> V_15 ) ;
if ( ! V_20 )
return - V_9 ;
return F_23 ( V_10 -> V_2 , V_52 , V_61 -> time , V_24 , V_20 ,
true ) ;
}
static int F_27 ( struct V_10 * V_10 ,
struct V_1 * V_2 ,
struct V_60 * V_61 ,
struct V_62 * V_63 ,
struct V_62 * V_64 , T_2 V_24 )
{
struct V_65 * V_55 = V_2 -> V_12 -> V_55 ;
struct V_57 * V_20 , * V_67 ;
T_2 V_68 = V_2 -> V_15 ;
int V_17 ;
if ( V_61 -> V_52 >= V_68 && V_61 -> V_66 < V_68 ) {
while ( F_8 ( V_2 ) ) {
V_17 = F_9 ( V_10 , V_2 , -- V_2 -> V_18 ,
V_61 -> time , V_24 ,
true ) ;
if ( V_17 )
return V_17 ;
}
if ( ! V_2 -> V_18 ) {
V_20 = F_26 ( V_55 , & V_55 -> V_57 ,
V_64 -> V_59 , V_61 -> V_66 ,
V_2 -> V_15 ) ;
if ( ! V_20 )
return - V_9 ;
return F_23 ( V_2 , 0 , V_61 -> time , V_24 ,
V_20 , true ) ;
}
} else if ( F_8 ( V_2 ) && V_61 -> V_52 < V_68 ) {
while ( F_8 ( V_2 ) ) {
V_17 = F_9 ( V_10 , V_2 , -- V_2 -> V_18 ,
V_61 -> time , V_24 ,
true ) ;
if ( V_17 )
return V_17 ;
}
}
if ( V_2 -> V_18 )
V_67 = V_2 -> V_8 [ V_2 -> V_18 - 1 ] . V_20 ;
else
V_67 = & V_55 -> V_57 ;
V_20 = F_26 ( V_55 , V_67 , V_63 -> V_59 , V_61 -> V_52 ,
V_2 -> V_15 ) ;
if ( ! V_20 )
return - V_9 ;
V_17 = F_23 ( V_2 , V_61 -> V_66 , V_61 -> time , V_24 , V_20 ,
true ) ;
if ( V_17 )
return V_17 ;
return F_24 ( V_10 , V_2 , V_61 -> V_66 , V_61 -> time , V_24 ,
V_64 -> V_59 ) ;
}
static int F_28 ( struct V_10 * V_10 ,
struct V_1 * V_2 , T_2 V_23 ,
T_2 V_24 )
{
struct V_3 * V_26 ;
int V_17 ;
if ( ! V_2 -> V_18 )
return 0 ;
V_26 = & V_2 -> V_8 [ V_2 -> V_18 - 1 ] ;
if ( V_26 -> V_20 -> V_59 == NULL && V_26 -> V_20 -> V_52 == 0 ) {
V_17 = F_9 ( V_10 , V_2 , -- V_2 -> V_18 ,
V_23 , V_24 , false ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_60 * V_61 , T_2 V_24 )
{
struct V_65 * V_55 = V_2 -> V_12 -> V_55 ;
struct V_57 * V_20 ;
T_2 V_16 ;
if ( ! V_2 -> V_18 || ( V_2 -> V_18 == 1 && V_2 -> V_8 [ 0 ] . V_24 == V_24 ) )
return 0 ;
V_20 = F_26 ( V_55 , V_2 -> V_8 [ V_2 -> V_18 - 1 ] . V_20 , NULL , 0 ,
V_2 -> V_15 ) ;
if ( ! V_20 )
return - V_9 ;
V_16 = V_61 -> V_52 + V_61 -> V_45 ;
return F_23 ( V_2 , V_16 , V_61 -> time , V_24 , V_20 ,
false ) ;
}
int F_30 ( struct V_10 * V_10 , struct V_29 * V_29 ,
struct V_60 * V_61 ,
struct V_62 * V_63 ,
struct V_62 * V_64 , T_2 V_24 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_17 = 0 ;
if ( V_2 ) {
if ( ! V_2 -> V_12 ) {
F_15 ( V_10 ) ;
V_10 -> V_2 = F_2 ( V_10 , V_12 ) ;
if ( ! V_10 -> V_2 )
return - V_9 ;
V_2 = V_10 -> V_2 ;
V_2 -> V_29 = V_29 ;
}
} else {
V_10 -> V_2 = F_2 ( V_10 , V_12 ) ;
if ( ! V_10 -> V_2 )
return - V_9 ;
V_2 = V_10 -> V_2 ;
V_2 -> V_29 = V_29 ;
}
if ( V_2 -> V_29 != V_29 && V_10 -> V_69 == V_10 -> V_70 ) {
V_17 = F_10 ( V_10 , V_2 ) ;
if ( V_17 )
return V_17 ;
V_2 -> V_29 = V_29 ;
}
if ( ! V_2 -> V_18 ) {
V_17 = F_25 ( V_10 , V_2 , V_61 , V_63 , V_64 ,
V_24 ) ;
if ( V_17 )
return V_17 ;
}
V_2 -> V_33 += 1 ;
V_2 -> V_42 = V_61 -> time ;
if ( V_61 -> V_37 & V_48 ) {
struct V_65 * V_55 = V_2 -> V_12 -> V_55 ;
struct V_57 * V_20 ;
T_2 V_16 ;
if ( ! V_61 -> V_52 || ! V_61 -> V_66 )
return 0 ;
V_16 = V_61 -> V_52 + V_61 -> V_45 ;
if ( V_16 == V_61 -> V_66 )
return 0 ;
V_20 = F_26 ( V_55 , V_2 -> V_8 [ V_2 -> V_18 - 1 ] . V_20 ,
V_64 -> V_59 , V_61 -> V_66 ,
V_2 -> V_15 ) ;
if ( ! V_20 )
return - V_9 ;
V_17 = F_23 ( V_2 , V_16 , V_61 -> time , V_24 ,
V_20 , false ) ;
} else if ( V_61 -> V_37 & V_49 ) {
if ( ! V_61 -> V_52 || ! V_61 -> V_66 )
return 0 ;
V_17 = F_24 ( V_10 , V_2 , V_61 -> V_66 ,
V_61 -> time , V_24 , V_63 -> V_59 ) ;
if ( V_17 ) {
if ( V_17 < 0 )
return V_17 ;
V_17 = F_27 ( V_10 , V_2 , V_61 ,
V_63 , V_64 , V_24 ) ;
}
} else if ( V_61 -> V_37 & V_71 ) {
V_17 = F_28 ( V_10 , V_2 , V_61 -> time , V_24 ) ;
} else if ( V_61 -> V_37 & V_72 ) {
V_17 = F_29 ( V_2 , V_61 , V_24 ) ;
}
return V_17 ;
}
T_1 F_31 ( struct V_10 * V_10 )
{
if ( ! V_10 -> V_2 )
return 0 ;
return V_10 -> V_2 -> V_18 ;
}
