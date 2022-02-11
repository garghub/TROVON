static inline void F_1 (
struct V_1 * V_2 ,
unsigned int * V_3 , unsigned int * V_4 )
{
* V_3 = V_2 -> V_5 ;
* V_4 = V_2 -> V_5 + V_2 -> V_6 - 1 ;
}
static unsigned int F_2 (
struct V_1 * V_2 , unsigned int V_7 ,
unsigned int V_8 )
{
return F_3 ( V_2 -> V_9 , V_7 , V_8 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
unsigned int V_7 , unsigned int V_10 ,
unsigned int V_8 )
{
F_5 ( V_2 -> V_9 , V_7 , V_10 , V_8 ) ;
}
static struct V_1 * F_6 ( struct V_11 * V_12 ,
unsigned int V_13 )
{
struct V_14 * V_15 = V_12 -> V_16 ;
struct V_17 * V_18 ;
struct V_1 * V_2 ;
unsigned int V_5 , V_19 ;
V_2 = V_15 -> V_20 ;
if ( V_2 ) {
F_1 ( V_2 , & V_5 , & V_19 ) ;
if ( V_13 >= V_5 && V_13 <= V_19 )
return V_2 ;
}
V_18 = V_15 -> V_21 . V_17 ;
while ( V_18 ) {
V_2 = F_7 ( V_18 , struct V_1 , V_18 ) ;
F_1 ( V_2 , & V_5 , & V_19 ) ;
if ( V_13 >= V_5 && V_13 <= V_19 ) {
V_15 -> V_20 = V_2 ;
return V_2 ;
} else if ( V_13 > V_19 ) {
V_18 = V_18 -> V_22 ;
} else if ( V_13 < V_5 ) {
V_18 = V_18 -> V_23 ;
}
}
return NULL ;
}
static int F_8 ( struct V_24 * V_21 ,
struct V_1 * V_2 )
{
struct V_17 * * V_25 , * V_26 ;
struct V_1 * V_27 ;
unsigned int V_28 , V_29 ;
unsigned int V_5 ;
V_26 = NULL ;
V_25 = & V_21 -> V_17 ;
while ( * V_25 ) {
V_27 = F_7 ( * V_25 , struct V_1 ,
V_18 ) ;
F_1 ( V_27 , & V_28 ,
& V_29 ) ;
V_5 = V_2 -> V_5 ;
V_26 = * V_25 ;
if ( V_5 >= V_28 &&
V_5 <= V_29 )
return 0 ;
else if ( V_5 > V_29 )
V_25 = & ( ( * V_25 ) -> V_22 ) ;
else if ( V_5 < V_28 )
V_25 = & ( ( * V_25 ) -> V_23 ) ;
}
F_9 ( & V_2 -> V_18 , V_26 , V_25 ) ;
F_10 ( & V_2 -> V_18 , V_21 ) ;
return 1 ;
}
static int F_11 ( struct V_30 * V_31 , void * V_32 )
{
struct V_11 * V_12 = V_31 -> V_33 ;
struct V_14 * V_15 = V_12 -> V_16 ;
struct V_1 * V_34 ;
struct V_17 * V_18 ;
unsigned int V_3 , V_4 ;
int V_35 = 0 ;
int V_36 = 0 ;
int V_37 ;
F_12 ( & V_12 -> V_38 ) ;
for ( V_18 = F_13 ( & V_15 -> V_21 ) ; V_18 != NULL ;
V_18 = F_14 ( V_18 ) ) {
V_34 = F_7 ( V_18 , struct V_1 , V_18 ) ;
F_1 ( V_34 , & V_3 , & V_4 ) ;
F_15 ( V_31 , L_1 , V_3 , V_4 , V_4 - V_3 + 1 ) ;
V_35 ++ ;
V_36 += V_4 - V_3 + 1 ;
}
if ( V_35 )
V_37 = V_36 / V_35 ;
else
V_37 = 0 ;
F_15 ( V_31 , L_2 ,
V_35 , V_36 , V_37 ) ;
F_16 ( & V_12 -> V_38 ) ;
return 0 ;
}
static int F_17 ( struct V_39 * V_39 , struct V_40 * V_40 )
{
return F_18 ( V_40 , F_11 , V_39 -> V_41 ) ;
}
static void F_19 ( struct V_11 * V_12 )
{
F_20 ( L_3 , 0400 , V_12 -> V_42 , V_12 , & V_43 ) ;
}
static void F_19 ( struct V_11 * V_12 )
{
}
static int F_21 ( struct V_11 * V_12 )
{
struct V_14 * V_15 ;
int V_44 ;
int V_45 ;
V_12 -> V_16 = F_22 ( sizeof *V_15 , V_46 ) ;
if ( ! V_12 -> V_16 )
return - V_47 ;
V_15 = V_12 -> V_16 ;
V_15 -> V_21 = V_48 ;
V_15 -> V_20 = NULL ;
for ( V_44 = 0 ; V_44 < V_12 -> V_49 ; V_44 ++ ) {
V_45 = F_23 ( V_12 ,
V_12 -> V_50 [ V_44 ] . V_13 ,
V_12 -> V_50 [ V_44 ] . V_51 ) ;
if ( V_45 )
goto V_52;
}
F_19 ( V_12 ) ;
return 0 ;
V_52:
F_24 ( V_12 ) ;
return V_45 ;
}
static int F_24 ( struct V_11 * V_12 )
{
struct V_17 * V_53 ;
struct V_14 * V_15 ;
struct V_1 * V_54 ;
V_15 = V_12 -> V_16 ;
if ( ! V_15 )
return 0 ;
V_53 = F_13 ( & V_15 -> V_21 ) ;
while ( V_53 ) {
V_54 = F_25 ( V_53 , struct V_1 , V_18 ) ;
V_53 = F_14 ( & V_54 -> V_18 ) ;
F_26 ( & V_54 -> V_18 , & V_15 -> V_21 ) ;
F_27 ( V_54 -> V_9 ) ;
F_27 ( V_54 ) ;
}
F_27 ( V_12 -> V_16 ) ;
V_12 -> V_16 = NULL ;
return 0 ;
}
static int F_28 ( struct V_11 * V_12 ,
unsigned int V_13 , unsigned int * V_55 )
{
struct V_1 * V_2 ;
unsigned int V_56 ;
V_2 = F_6 ( V_12 , V_13 ) ;
if ( V_2 ) {
V_56 = V_13 - V_2 -> V_5 ;
* V_55 = F_2 ( V_2 , V_56 ,
V_12 -> V_57 ) ;
} else {
return - V_58 ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
unsigned int V_59 , unsigned int V_13 ,
unsigned int V_55 , unsigned int V_8 )
{
T_1 * V_60 ;
V_60 = F_30 ( V_2 -> V_9 ,
( V_2 -> V_6 + 1 ) * V_8 , V_46 ) ;
if ( ! V_60 )
return - V_47 ;
memmove ( V_60 + ( V_59 + 1 ) * V_8 ,
V_60 + V_59 * V_8 ,
( V_2 -> V_6 - V_59 ) * V_8 ) ;
V_2 -> V_9 = V_60 ;
V_2 -> V_6 ++ ;
if ( ! V_59 )
V_2 -> V_5 = V_13 ;
F_4 ( V_2 , V_59 , V_55 , V_8 ) ;
return 0 ;
}
static int F_23 ( struct V_11 * V_12 , unsigned int V_13 ,
unsigned int V_55 )
{
struct V_14 * V_15 ;
struct V_1 * V_2 , * V_27 ;
struct V_17 * V_18 ;
unsigned int V_10 ;
unsigned int V_56 ;
unsigned int V_59 ;
int V_44 ;
int V_45 ;
V_15 = V_12 -> V_16 ;
V_2 = F_6 ( V_12 , V_13 ) ;
if ( V_2 ) {
V_56 = V_13 - V_2 -> V_5 ;
V_10 = F_2 ( V_2 , V_56 ,
V_12 -> V_57 ) ;
if ( V_10 == V_55 )
return 0 ;
F_4 ( V_2 , V_56 , V_55 ,
V_12 -> V_57 ) ;
} else {
for ( V_18 = F_13 ( & V_15 -> V_21 ) ; V_18 ;
V_18 = F_14 ( V_18 ) ) {
V_27 = F_25 ( V_18 , struct V_1 , V_18 ) ;
for ( V_44 = 0 ; V_44 < V_27 -> V_6 ; V_44 ++ ) {
V_56 = V_27 -> V_5 + V_44 ;
if ( abs ( V_56 - V_13 ) != 1 )
continue;
if ( V_56 + 1 == V_13 )
V_59 = V_44 + 1 ;
else
V_59 = V_44 ;
V_45 = F_29 ( V_27 , V_59 ,
V_13 , V_55 ,
V_12 -> V_57 ) ;
if ( V_45 )
return V_45 ;
V_15 -> V_20 = V_27 ;
return 0 ;
}
}
V_2 = F_31 ( sizeof *V_2 , V_46 ) ;
if ( ! V_2 )
return - V_47 ;
V_2 -> V_6 = 1 ;
V_2 -> V_5 = V_13 ;
V_2 -> V_9 = F_22 ( V_2 -> V_6 * V_12 -> V_57 ,
V_46 ) ;
if ( ! V_2 -> V_9 ) {
F_27 ( V_2 ) ;
return - V_47 ;
}
F_4 ( V_2 , 0 , V_55 , V_12 -> V_57 ) ;
F_8 ( & V_15 -> V_21 , V_2 ) ;
V_15 -> V_20 = V_2 ;
}
return 0 ;
}
static int F_32 ( struct V_11 * V_12 , unsigned int V_61 ,
unsigned int V_62 )
{
struct V_14 * V_15 ;
struct V_17 * V_18 ;
struct V_1 * V_2 ;
unsigned int V_63 ;
unsigned int V_10 ;
int V_45 ;
int V_44 , V_3 , V_64 ;
V_15 = V_12 -> V_16 ;
for ( V_18 = F_13 ( & V_15 -> V_21 ) ; V_18 ; V_18 = F_14 ( V_18 ) ) {
V_2 = F_25 ( V_18 , struct V_1 , V_18 ) ;
if ( V_2 -> V_5 < V_61 )
continue;
if ( V_2 -> V_5 > V_62 )
break;
if ( V_2 -> V_5 + V_2 -> V_6 < V_61 )
continue;
if ( V_61 > V_2 -> V_5 )
V_3 = V_61 - V_2 -> V_5 ;
else
V_3 = 0 ;
if ( V_62 < V_2 -> V_5 + V_2 -> V_6 )
V_64 = V_2 -> V_5 + V_2 -> V_6 - V_62 ;
else
V_64 = V_2 -> V_6 ;
for ( V_44 = V_3 ; V_44 < V_64 ; V_44 ++ ) {
V_63 = V_2 -> V_5 + V_44 ;
V_10 = F_2 ( V_2 , V_44 ,
V_12 -> V_57 ) ;
V_45 = F_33 ( V_12 , V_63 ) ;
if ( V_45 >= 0 && V_10 == V_12 -> V_50 [ V_45 ] . V_51 )
continue;
V_12 -> V_65 = 1 ;
V_45 = F_34 ( V_12 , V_63 , V_10 ) ;
V_12 -> V_65 = 0 ;
if ( V_45 )
return V_45 ;
F_35 ( V_12 -> V_66 , L_4 ,
V_63 , V_10 ) ;
}
}
return 0 ;
}
