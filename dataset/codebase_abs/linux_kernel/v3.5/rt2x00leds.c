void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
unsigned int V_7 ;
if ( ( V_5 -> type != V_8 ) || ! ( V_5 -> V_9 & V_10 ) )
return;
V_3 += V_2 -> V_11 ;
if ( V_3 <= 30 )
V_3 = 0 ;
else if ( V_3 <= 39 )
V_3 = 1 ;
else if ( V_3 <= 49 )
V_3 = 2 ;
else if ( V_3 <= 53 )
V_3 = 3 ;
else if ( V_3 <= 63 )
V_3 = 4 ;
else
V_3 = 5 ;
V_7 = ( ( V_12 / 6 ) * V_3 ) + 1 ;
if ( V_7 != V_5 -> V_13 . V_7 ) {
V_5 -> V_13 . V_14 ( & V_5 -> V_13 , V_7 ) ;
V_5 -> V_13 . V_7 = V_7 ;
}
}
static void F_2 ( struct V_4 * V_5 , bool V_15 )
{
unsigned int V_7 = V_15 ? V_12 : V_16 ;
if ( ! ( V_5 -> V_9 & V_10 ) )
return;
V_5 -> V_13 . V_14 ( & V_5 -> V_13 , V_7 ) ;
V_5 -> V_13 . V_7 = V_7 ;
}
void F_3 ( struct V_1 * V_2 , bool V_15 )
{
if ( V_2 -> V_6 . type == V_17 )
F_2 ( & V_2 -> V_6 , V_15 ) ;
}
void F_4 ( struct V_1 * V_2 , bool V_15 )
{
if ( V_2 -> V_18 . type == V_19 )
F_2 ( & V_2 -> V_18 , V_15 ) ;
}
void F_5 ( struct V_1 * V_2 , bool V_15 )
{
if ( V_2 -> V_20 . type == V_21 )
F_2 ( & V_2 -> V_20 , V_15 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
const char * V_22 )
{
struct V_23 * V_23 = F_7 ( V_2 -> V_24 -> V_25 ) ;
int V_26 ;
V_5 -> V_13 . V_22 = V_22 ;
V_5 -> V_13 . V_7 = V_16 ;
V_26 = F_8 ( V_23 , & V_5 -> V_13 ) ;
if ( V_26 ) {
ERROR ( V_2 , L_1 ) ;
return V_26 ;
}
V_5 -> V_9 |= V_10 ;
return 0 ;
}
void F_9 ( struct V_1 * V_2 )
{
char V_22 [ 36 ] ;
int V_26 ;
unsigned long V_27 ;
unsigned long V_28 ;
const char * V_29 = F_10 ( V_2 -> V_24 -> V_25 ) ;
if ( V_2 -> V_20 . V_9 & V_30 ) {
snprintf ( V_22 , sizeof( V_22 ) , L_2 ,
V_2 -> V_31 -> V_22 , V_29 ) ;
V_26 = F_6 ( V_2 ,
& V_2 -> V_20 ,
V_22 ) ;
if ( V_26 )
goto V_32;
}
if ( V_2 -> V_18 . V_9 & V_30 ) {
snprintf ( V_22 , sizeof( V_22 ) , L_3 ,
V_2 -> V_31 -> V_22 , V_29 ) ;
V_26 = F_6 ( V_2 ,
& V_2 -> V_18 ,
V_22 ) ;
if ( V_26 )
goto V_32;
}
if ( V_2 -> V_6 . V_9 & V_30 ) {
snprintf ( V_22 , sizeof( V_22 ) , L_4 ,
V_2 -> V_31 -> V_22 , V_29 ) ;
V_26 = F_6 ( V_2 ,
& V_2 -> V_6 ,
V_22 ) ;
if ( V_26 )
goto V_32;
}
if ( V_2 -> V_20 . V_13 . V_33 ) {
V_27 = 70 ;
V_28 = 30 ;
V_2 -> V_20 . V_13 . V_33 (
& V_2 -> V_20 . V_13 , & V_27 , & V_28 ) ;
}
return;
V_32:
F_11 ( V_2 ) ;
}
static void F_12 ( struct V_4 * V_5 )
{
F_13 ( & V_5 -> V_13 ) ;
if ( ! ( V_5 -> V_13 . V_9 & V_34 ) )
V_5 -> V_13 . V_14 ( & V_5 -> V_13 , V_16 ) ;
V_5 -> V_9 &= ~ V_10 ;
}
void F_11 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 . V_9 & V_10 )
F_12 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_18 . V_9 & V_10 )
F_12 ( & V_2 -> V_18 ) ;
if ( V_2 -> V_20 . V_9 & V_10 )
F_12 ( & V_2 -> V_20 ) ;
}
static inline void F_14 ( struct V_4 * V_5 )
{
F_15 ( & V_5 -> V_13 ) ;
V_5 -> V_13 . V_14 ( & V_5 -> V_13 , V_16 ) ;
V_5 -> V_13 . V_7 = V_16 ;
}
void F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 . V_9 & V_10 )
F_14 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_18 . V_9 & V_10 )
F_14 ( & V_2 -> V_18 ) ;
if ( V_2 -> V_20 . V_9 & V_10 )
F_14 ( & V_2 -> V_20 ) ;
}
static inline void F_17 ( struct V_4 * V_5 )
{
F_18 ( & V_5 -> V_13 ) ;
V_5 -> V_13 . V_14 ( & V_5 -> V_13 , V_16 ) ;
V_5 -> V_13 . V_7 = V_16 ;
}
void F_19 ( struct V_1 * V_2 )
{
if ( V_2 -> V_20 . V_9 & V_10 )
F_17 ( & V_2 -> V_20 ) ;
if ( V_2 -> V_18 . V_9 & V_10 )
F_17 ( & V_2 -> V_18 ) ;
if ( V_2 -> V_6 . V_9 & V_10 )
F_17 ( & V_2 -> V_6 ) ;
}
