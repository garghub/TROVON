int F_1 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
F_2 ( V_6 , V_7 ) ;
struct F_1 * V_8 = V_3 ;
struct V_9 * V_10 = V_5 -> V_10 ;
int V_11 = 0 ;
++ V_5 -> V_12 ;
if ( V_8 -> V_13 == V_14 ) {
F_3 ( L_1 ,
F_4 ( V_7 ) , V_8 -> V_13 ) ;
return - V_15 ;
}
F_5 ( L_2 ,
V_8 -> V_13 , F_4 ( V_7 ) ,
V_10 -> V_8 . V_16 -> V_8 , V_8 -> V_17 ) ;
if ( F_6 ( V_2 , V_18 ) )
if ( V_8 -> V_13 < 0 )
return - V_15 ;
F_7 ( & V_10 -> V_8 . V_19 , & V_6 ) ;
F_8 ( & V_10 -> V_8 . V_20 ) ;
V_10 -> V_8 . V_21 ++ ;
F_9 ( & V_10 -> V_8 . V_20 ) ;
for (; ; ) {
F_10 ( V_22 ) ;
if ( ! V_10 -> V_8 . V_16 ) {
F_11 ( V_23 , V_7 , 0 ) ;
V_11 = - V_24 ;
break;
}
if ( F_12 ( & V_10 -> V_8 , V_8 -> V_13 ) ) {
V_10 -> V_8 . V_5 = V_5 ;
V_10 -> V_8 . V_25 = V_26 ;
F_13 ( & V_2 -> V_27 [ V_28 ] ) ;
break;
}
F_14 ( & V_29 ) ;
F_15 () ;
F_16 ( & V_29 ) ;
if ( F_17 ( V_7 ) ) {
V_11 = - V_24 ;
break;
}
}
F_8 ( & V_10 -> V_8 . V_20 ) ;
V_10 -> V_8 . V_21 -- ;
F_9 ( & V_10 -> V_8 . V_20 ) ;
F_10 ( V_30 ) ;
F_18 ( & V_10 -> V_8 . V_19 , & V_6 ) ;
F_5 ( L_3 , V_8 -> V_13 ,
V_11 ? L_4 : L_5 ) ;
if ( V_11 ) return V_11 ;
if ( ! V_5 -> V_31 ) {
F_19 ( & V_2 -> V_32 ) ;
F_20 ( & V_2 -> V_32 , V_33 ) ;
F_20 ( & V_2 -> V_32 , V_34 ) ;
F_20 ( & V_2 -> V_32 , V_35 ) ;
F_20 ( & V_2 -> V_32 , V_36 ) ;
V_2 -> V_37 . V_13 = V_8 -> V_13 ;
V_2 -> V_37 . V_8 = V_10 -> V_8 . V_16 ;
F_21 ( V_38 , & V_2 -> V_37 , & V_2 -> V_32 ) ;
}
if ( V_2 -> V_39 -> V_40 && ( V_8 -> V_17 & V_41 ) )
{
if ( V_2 -> V_39 -> V_40 ( V_2 ) ) {
F_5 ( L_6 ,
V_8 -> V_13 ) ;
return - V_42 ;
}
}
return 0 ;
}
int F_22 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct F_1 * V_8 = V_3 ;
struct V_9 * V_10 = V_5 -> V_10 ;
if ( V_8 -> V_13 == V_14 ) {
F_3 ( L_1 ,
F_4 ( V_7 ) , V_8 -> V_13 ) ;
return - V_15 ;
}
F_13 ( & V_2 -> V_27 [ V_43 ] ) ;
if ( F_23 ( & V_10 -> V_8 , V_8 -> V_13 ) ) {
}
F_24 () ;
return 0 ;
}
static
int F_12 ( struct V_44 * V_45 ,
unsigned int V_13 )
{
unsigned int V_46 , V_47 , V_48 ;
volatile unsigned int * V_8 = & V_45 -> V_16 -> V_8 ;
F_8 ( & V_45 -> V_20 ) ;
do {
V_46 = * V_8 ;
if ( V_46 & V_49 )
V_47 = V_46 | V_50 ;
else {
V_47 = V_13 | V_49 |
( ( V_45 -> V_21 + V_45 -> V_51 > 1 ) ?
V_50 : 0 ) ;
}
V_48 = F_25 ( V_8 , V_46 , V_47 ) ;
} while ( V_48 != V_46 );
F_9 ( & V_45 -> V_20 ) ;
if ( F_26 ( V_46 ) == V_13 ) {
if ( V_46 & V_49 ) {
if ( V_13 != V_14 ) {
F_3 ( L_7 ,
V_13 ) ;
}
return 0 ;
}
}
if ( ( F_26 ( V_47 ) ) == V_13 && ( V_47 & V_49 ) ) {
return 1 ;
}
return 0 ;
}
static int F_27 ( struct V_44 * V_45 ,
unsigned int V_13 )
{
unsigned int V_46 , V_47 , V_48 ;
volatile unsigned int * V_8 = & V_45 -> V_16 -> V_8 ;
V_45 -> V_5 = NULL ;
do {
V_46 = * V_8 ;
V_47 = V_13 | V_49 ;
V_48 = F_25 ( V_8 , V_46 , V_47 ) ;
} while ( V_48 != V_46 );
return 1 ;
}
int F_23 ( struct V_44 * V_45 , unsigned int V_13 )
{
unsigned int V_46 , V_47 , V_48 ;
volatile unsigned int * V_8 = & V_45 -> V_16 -> V_8 ;
F_8 ( & V_45 -> V_20 ) ;
if ( V_45 -> V_51 != 0 ) {
F_27 ( V_45 , 0 ) ;
V_45 -> V_52 = 1 ;
F_9 ( & V_45 -> V_20 ) ;
return 1 ;
}
F_9 ( & V_45 -> V_20 ) ;
do {
V_46 = * V_8 ;
V_47 = F_26 ( V_46 ) ;
V_48 = F_25 ( V_8 , V_46 , V_47 ) ;
} while ( V_48 != V_46 );
if ( F_28 ( V_46 ) && F_26 ( V_46 ) != V_13 ) {
F_3 ( L_8 ,
V_13 , F_26 ( V_46 ) ) ;
return 1 ;
}
F_29 ( & V_45 -> V_19 ) ;
return 0 ;
}
static int V_38 ( void * V_53 )
{
struct V_54 * V_55 = (struct V_54 * ) V_53 ;
unsigned int V_46 , V_47 , V_48 ;
if ( ! V_55 -> V_8 || ! F_28 ( V_55 -> V_8 -> V_8 )
|| F_26 ( V_55 -> V_8 -> V_8 ) != V_55 -> V_13 )
return 1 ;
do {
V_46 = V_55 -> V_8 -> V_8 ;
V_47 = V_46 | V_50 ;
V_48 = F_25 ( & V_55 -> V_8 -> V_8 , V_46 , V_47 ) ;
} while ( V_48 != V_46 );
return 0 ;
}
void F_30 ( struct V_44 * V_45 )
{
int V_11 ;
F_8 ( & V_45 -> V_20 ) ;
V_45 -> V_51 ++ ;
if ( ! V_45 -> V_52 ) {
F_9 ( & V_45 -> V_20 ) ;
V_11 = F_12 ( V_45 , V_14 ) ;
F_8 ( & V_45 -> V_20 ) ;
if ( V_11 == 1 )
V_45 -> V_52 = 1 ;
}
F_9 ( & V_45 -> V_20 ) ;
}
void F_31 ( struct V_44 * V_45 )
{
unsigned int V_46 , V_48 ;
volatile unsigned int * V_8 = & V_45 -> V_16 -> V_8 ;
F_8 ( & V_45 -> V_20 ) ;
if ( -- V_45 -> V_51 == 0 ) {
if ( V_45 -> V_52 ) {
do {
V_46 = * V_8 ;
V_48 = F_25 ( V_8 , V_46 , V_14 ) ;
} while ( V_48 != V_46 );
F_29 ( & V_45 -> V_19 ) ;
V_45 -> V_52 = 0 ;
}
}
F_9 ( & V_45 -> V_20 ) ;
}
int F_32 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_10 ;
return ( V_5 -> V_12 && V_10 -> V_8 . V_16 &&
F_28 ( V_10 -> V_8 . V_16 -> V_8 ) &&
V_10 -> V_8 . V_5 == V_5 ) ;
}
