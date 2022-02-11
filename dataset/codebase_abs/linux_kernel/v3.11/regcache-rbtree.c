static inline void F_1 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int * V_5 , unsigned int * V_6 )
{
* V_5 = V_4 -> V_7 ;
* V_6 = V_4 -> V_7 + ( ( V_4 -> V_8 - 1 ) * V_2 -> V_9 ) ;
}
static unsigned int F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int V_10 )
{
return F_3 ( V_2 , V_4 -> V_11 , V_10 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_10 , unsigned int V_12 )
{
F_5 ( V_2 , V_4 -> V_11 , V_10 , V_12 ) ;
}
static struct V_3 * F_6 ( struct V_1 * V_2 ,
unsigned int V_13 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
struct V_17 * V_18 ;
struct V_3 * V_4 ;
unsigned int V_7 , V_19 ;
V_4 = V_15 -> V_20 ;
if ( V_4 ) {
F_1 ( V_2 , V_4 , & V_7 ,
& V_19 ) ;
if ( V_13 >= V_7 && V_13 <= V_19 )
return V_4 ;
}
V_18 = V_15 -> V_21 . V_17 ;
while ( V_18 ) {
V_4 = F_7 ( V_18 , struct V_3 , V_18 ) ;
F_1 ( V_2 , V_4 , & V_7 ,
& V_19 ) ;
if ( V_13 >= V_7 && V_13 <= V_19 ) {
V_15 -> V_20 = V_4 ;
return V_4 ;
} else if ( V_13 > V_19 ) {
V_18 = V_18 -> V_22 ;
} else if ( V_13 < V_7 ) {
V_18 = V_18 -> V_23 ;
}
}
return NULL ;
}
static int F_8 ( struct V_1 * V_2 , struct V_24 * V_21 ,
struct V_3 * V_4 )
{
struct V_17 * * V_25 , * V_26 ;
struct V_3 * V_27 ;
unsigned int V_28 , V_29 ;
unsigned int V_7 ;
V_26 = NULL ;
V_25 = & V_21 -> V_17 ;
while ( * V_25 ) {
V_27 = F_7 ( * V_25 , struct V_3 ,
V_18 ) ;
F_1 ( V_2 , V_27 , & V_28 ,
& V_29 ) ;
V_7 = V_4 -> V_7 ;
V_26 = * V_25 ;
if ( V_7 >= V_28 &&
V_7 <= V_29 )
return 0 ;
else if ( V_7 > V_29 )
V_25 = & ( ( * V_25 ) -> V_22 ) ;
else if ( V_7 < V_28 )
V_25 = & ( ( * V_25 ) -> V_23 ) ;
}
F_9 ( & V_4 -> V_18 , V_26 , V_25 ) ;
F_10 ( & V_4 -> V_18 , V_21 ) ;
return 1 ;
}
static int F_11 ( struct V_30 * V_31 , void * V_32 )
{
struct V_1 * V_2 = V_31 -> V_33 ;
struct V_14 * V_15 = V_2 -> V_16 ;
struct V_3 * V_34 ;
struct V_17 * V_18 ;
unsigned int V_5 , V_6 ;
T_1 V_35 ;
int V_36 = 0 ;
int V_37 = 0 ;
int V_38 , V_39 ;
V_2 -> V_40 ( V_2 -> V_41 ) ;
V_35 = sizeof( * V_15 ) ;
V_35 += F_12 ( V_2 -> V_42 ) * sizeof( long ) ;
for ( V_18 = F_13 ( & V_15 -> V_21 ) ; V_18 != NULL ;
V_18 = F_14 ( V_18 ) ) {
V_34 = F_7 ( V_18 , struct V_3 , V_18 ) ;
V_35 += sizeof( * V_34 ) ;
V_35 += ( V_34 -> V_8 * V_2 -> V_43 ) ;
F_1 ( V_2 , V_34 , & V_5 , & V_6 ) ;
V_38 = ( ( V_6 - V_5 ) / V_2 -> V_9 ) + 1 ;
F_15 ( V_31 , L_1 , V_5 , V_6 , V_38 ) ;
V_36 ++ ;
V_37 += V_38 ;
}
if ( V_36 )
V_39 = V_37 / V_36 ;
else
V_39 = 0 ;
F_15 ( V_31 , L_2 ,
V_36 , V_37 , V_39 , V_35 ) ;
V_2 -> V_44 ( V_2 -> V_41 ) ;
return 0 ;
}
static int F_16 ( struct V_45 * V_45 , struct V_46 * V_46 )
{
return F_17 ( V_46 , F_11 , V_45 -> V_47 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_19 ( L_3 , 0400 , V_2 -> V_48 , V_2 , & V_49 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
int V_50 ;
int V_51 ;
V_2 -> V_16 = F_21 ( sizeof *V_15 , V_52 ) ;
if ( ! V_2 -> V_16 )
return - V_53 ;
V_15 = V_2 -> V_16 ;
V_15 -> V_21 = V_54 ;
V_15 -> V_20 = NULL ;
for ( V_50 = 0 ; V_50 < V_2 -> V_55 ; V_50 ++ ) {
V_51 = F_22 ( V_2 ,
V_2 -> V_56 [ V_50 ] . V_13 ,
V_2 -> V_56 [ V_50 ] . V_57 ) ;
if ( V_51 )
goto V_58;
}
F_18 ( V_2 ) ;
return 0 ;
V_58:
F_23 ( V_2 ) ;
return V_51 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_17 * V_59 ;
struct V_14 * V_15 ;
struct V_3 * V_60 ;
V_15 = V_2 -> V_16 ;
if ( ! V_15 )
return 0 ;
V_59 = F_13 ( & V_15 -> V_21 ) ;
while ( V_59 ) {
V_60 = F_24 ( V_59 , struct V_3 , V_18 ) ;
V_59 = F_14 ( & V_60 -> V_18 ) ;
F_25 ( & V_60 -> V_18 , & V_15 -> V_21 ) ;
F_26 ( V_60 -> V_11 ) ;
F_26 ( V_60 ) ;
}
F_26 ( V_2 -> V_16 ) ;
V_2 -> V_16 = NULL ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
unsigned int V_13 , unsigned int * V_61 )
{
struct V_3 * V_4 ;
unsigned int V_62 ;
V_4 = F_6 ( V_2 , V_13 ) ;
if ( V_4 ) {
V_62 = ( V_13 - V_4 -> V_7 ) / V_2 -> V_9 ;
if ( ! F_28 ( V_2 , V_13 ) )
return - V_63 ;
* V_61 = F_2 ( V_2 , V_4 , V_62 ) ;
} else {
return - V_63 ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_64 , unsigned int V_13 ,
unsigned int V_61 )
{
T_2 * V_65 ;
V_65 = F_30 ( V_4 -> V_11 ,
( V_4 -> V_8 + 1 ) * V_2 -> V_43 ,
V_52 ) ;
if ( ! V_65 )
return - V_53 ;
memmove ( V_65 + ( V_64 + 1 ) * V_2 -> V_43 ,
V_65 + V_64 * V_2 -> V_43 ,
( V_4 -> V_8 - V_64 ) * V_2 -> V_43 ) ;
V_4 -> V_11 = V_65 ;
V_4 -> V_8 ++ ;
if ( ! V_64 )
V_4 -> V_7 = V_13 ;
F_4 ( V_2 , V_4 , V_64 , V_61 ) ;
return 0 ;
}
static struct V_3 *
F_31 ( struct V_1 * V_2 , unsigned int V_13 )
{
struct V_3 * V_4 ;
const struct V_66 * V_67 ;
int V_50 ;
V_4 = F_32 ( sizeof( * V_4 ) , V_52 ) ;
if ( ! V_4 )
return NULL ;
if ( V_2 -> V_68 ) {
for ( V_50 = 0 ; V_50 < V_2 -> V_68 -> V_69 ; V_50 ++ ) {
if ( F_33 ( V_13 ,
& V_2 -> V_68 -> V_70 [ V_50 ] ) )
break;
}
if ( V_50 != V_2 -> V_68 -> V_69 ) {
V_67 = & V_2 -> V_68 -> V_70 [ V_50 ] ;
V_4 -> V_8 = V_67 -> V_71 - V_67 -> V_72
+ 1 ;
V_4 -> V_7 = V_67 -> V_72 ;
}
}
if ( ! V_4 -> V_8 ) {
V_4 -> V_8 = 1 ;
V_4 -> V_7 = V_13 ;
}
V_4 -> V_11 = F_21 ( V_4 -> V_8 * V_2 -> V_43 ,
V_52 ) ;
if ( ! V_4 -> V_11 ) {
F_26 ( V_4 ) ;
return NULL ;
}
return V_4 ;
}
static int F_22 ( struct V_1 * V_2 , unsigned int V_13 ,
unsigned int V_61 )
{
struct V_14 * V_15 ;
struct V_3 * V_4 , * V_27 ;
struct V_17 * V_18 ;
unsigned int V_62 ;
unsigned int V_64 ;
int V_50 ;
int V_51 ;
V_15 = V_2 -> V_16 ;
V_51 = F_34 ( V_2 , V_13 ) ;
if ( V_51 < 0 )
return V_51 ;
V_4 = F_6 ( V_2 , V_13 ) ;
if ( V_4 ) {
V_62 = ( V_13 - V_4 -> V_7 ) / V_2 -> V_9 ;
F_4 ( V_2 , V_4 , V_62 , V_61 ) ;
} else {
for ( V_18 = F_13 ( & V_15 -> V_21 ) ; V_18 ;
V_18 = F_14 ( V_18 ) ) {
V_27 = F_24 ( V_18 , struct V_3 ,
V_18 ) ;
for ( V_50 = 0 ; V_50 < V_27 -> V_8 ; V_50 ++ ) {
V_62 = V_27 -> V_7 +
( V_50 * V_2 -> V_9 ) ;
if ( abs ( V_62 - V_13 ) != V_2 -> V_9 )
continue;
if ( V_62 + V_2 -> V_9 == V_13 )
V_64 = V_50 + 1 ;
else
V_64 = V_50 ;
V_51 = F_29 ( V_2 ,
V_27 ,
V_64 , V_13 ,
V_61 ) ;
if ( V_51 )
return V_51 ;
V_15 -> V_20 = V_27 ;
return 0 ;
}
}
V_4 = F_31 ( V_2 , V_13 ) ;
if ( ! V_4 )
return - V_53 ;
F_4 ( V_2 , V_4 ,
V_13 - V_4 -> V_7 , V_61 ) ;
F_8 ( V_2 , & V_15 -> V_21 , V_4 ) ;
V_15 -> V_20 = V_4 ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , unsigned int V_73 ,
unsigned int V_74 )
{
struct V_14 * V_15 ;
struct V_17 * V_18 ;
struct V_3 * V_4 ;
int V_51 ;
int V_5 , V_75 ;
V_15 = V_2 -> V_16 ;
for ( V_18 = F_13 ( & V_15 -> V_21 ) ; V_18 ; V_18 = F_14 ( V_18 ) ) {
V_4 = F_24 ( V_18 , struct V_3 , V_18 ) ;
if ( V_4 -> V_7 > V_74 )
break;
if ( V_4 -> V_7 + V_4 -> V_8 < V_73 )
continue;
if ( V_73 > V_4 -> V_7 )
V_5 = V_73 - V_4 -> V_7 ;
else
V_5 = 0 ;
if ( V_74 < V_4 -> V_7 + V_4 -> V_8 )
V_75 = V_74 - V_4 -> V_7 + 1 ;
else
V_75 = V_4 -> V_8 ;
V_51 = F_36 ( V_2 , V_4 -> V_11 , V_4 -> V_7 ,
V_5 , V_75 ) ;
if ( V_51 != 0 )
return V_51 ;
}
return F_37 ( V_2 ) ;
}
