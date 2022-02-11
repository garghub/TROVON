static int F_1 ( unsigned int V_1 , unsigned int * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
if ( V_5 [ V_3 ] == V_1 )
break;
}
if ( V_3 == V_4 )
return - V_6 ;
* V_2 = ( ( int ) V_3 - 1 ) / 2 ;
return 0 ;
}
static int F_2 ( struct V_7 * V_8 , unsigned int V_1 )
{
int V_2 ;
int V_9 ;
V_9 = F_1 ( V_1 , & V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_3 ( & V_8 -> V_10 , V_1 ,
V_8 -> V_11 -> V_12 [ V_2 ] ) ;
if ( V_9 < 0 )
return V_9 ;
V_8 -> V_13 . V_14 = 0x00000000000000ffuLL ;
V_9 = F_4 ( & V_8 -> V_13 ,
F_5 ( & V_8 -> V_10 ) ,
F_6 ( V_8 -> V_15 ) -> V_16 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_3 ( & V_8 -> V_17 , V_1 ,
V_8 -> V_11 -> V_18 [ V_2 ] ) ;
if ( V_9 < 0 )
return V_9 ;
V_8 -> V_19 . V_14 = 0x00000000000000ffuLL ;
V_9 = F_4 ( & V_8 -> V_19 ,
F_5 ( & V_8 -> V_17 ) ,
F_6 ( V_8 -> V_15 ) -> V_16 ) ;
if ( V_9 < 0 )
F_7 ( & V_8 -> V_13 ) ;
return V_9 ;
}
static void F_8 ( struct V_7 * V_8 )
{
F_7 ( & V_8 -> V_13 ) ;
F_7 ( & V_8 -> V_19 ) ;
}
static inline void F_9 ( struct V_7 * V_8 )
{
V_8 -> V_11 -> V_20 -> F_9 ( V_8 ) ;
V_8 -> V_11 -> V_20 -> V_21 ( V_8 , false ) ;
}
static int F_10 ( struct V_7 * V_8 , enum V_22 V_23 )
{
int V_9 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
if ( V_23 == V_28 ) {
V_25 = & V_8 -> V_13 ;
V_27 = & V_8 -> V_10 ;
} else {
V_25 = & V_8 -> V_19 ;
V_27 = & V_8 -> V_17 ;
}
V_9 = F_11 ( V_25 , V_8 -> V_15 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_12 ( V_27 , V_8 -> V_15 , V_23 ) ;
if ( V_9 < 0 )
F_13 ( V_25 ) ;
return V_9 ;
}
static void F_14 ( struct V_7 * V_8 , enum V_22 V_23 )
{
if ( V_23 == V_28 ) {
F_15 ( & V_8 -> V_10 ) ;
F_13 ( & V_8 -> V_13 ) ;
} else {
F_15 ( & V_8 -> V_17 ) ;
F_13 ( & V_8 -> V_19 ) ;
}
}
int F_16 ( struct V_7 * V_8 )
{
int V_9 ;
V_9 = F_10 ( V_8 , V_29 ) ;
if ( V_9 < 0 )
goto V_30;
V_9 = F_10 ( V_8 , V_28 ) ;
if ( V_9 < 0 )
F_14 ( V_8 , V_29 ) ;
V_30:
return V_9 ;
}
void F_17 ( struct V_7 * V_8 )
{
F_14 ( V_8 , V_28 ) ;
F_14 ( V_8 , V_29 ) ;
}
int F_18 ( struct V_7 * V_8 , unsigned int V_1 )
{
unsigned int V_31 ;
enum V_32 V_33 ;
int V_9 ;
if ( V_8 -> V_34 == 0 )
return 0 ;
V_9 = V_8 -> V_11 -> V_20 -> V_35 ( V_8 , & V_31 , & V_33 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_31 != V_1 ||
F_19 ( & V_8 -> V_10 ) ||
F_19 ( & V_8 -> V_17 ) ) {
F_9 ( V_8 ) ;
F_20 ( & V_8 -> V_10 ) ;
F_20 ( & V_8 -> V_17 ) ;
F_8 ( V_8 ) ;
}
if ( ! F_21 ( & V_8 -> V_17 ) ) {
V_9 = F_2 ( V_8 , V_1 ) ;
if ( V_9 < 0 )
goto error;
V_9 = V_8 -> V_11 -> V_20 -> V_36 ( V_8 , V_1 ) ;
if ( V_9 < 0 )
goto error;
V_9 = F_22 ( & V_8 -> V_17 ,
V_8 -> V_19 . V_37 ,
F_6 ( V_8 -> V_15 ) -> V_16 ) ;
if ( V_9 < 0 )
goto error;
if ( ! F_23 ( & V_8 -> V_17 ,
V_38 ) ) {
V_9 = - V_39 ;
goto error;
}
V_9 = V_8 -> V_11 -> V_20 -> V_21 ( V_8 , true ) ;
if ( V_9 < 0 )
goto error;
}
if ( ! F_21 ( & V_8 -> V_10 ) ) {
V_9 = F_22 ( & V_8 -> V_10 ,
V_8 -> V_13 . V_37 ,
F_6 ( V_8 -> V_15 ) -> V_16 ) ;
if ( V_9 < 0 )
goto error;
if ( ! F_23 ( & V_8 -> V_10 ,
V_38 ) ) {
V_9 = - V_39 ;
goto error;
}
}
return 0 ;
error:
F_20 ( & V_8 -> V_10 ) ;
F_20 ( & V_8 -> V_17 ) ;
F_9 ( V_8 ) ;
F_8 ( V_8 ) ;
return V_9 ;
}
void F_24 ( struct V_7 * V_8 )
{
if ( V_8 -> V_34 > 0 )
return;
F_20 ( & V_8 -> V_10 ) ;
F_20 ( & V_8 -> V_17 ) ;
F_9 ( V_8 ) ;
F_8 ( V_8 ) ;
}
void F_25 ( struct V_7 * V_8 )
{
F_26 ( & V_8 -> V_10 ) ;
F_20 ( & V_8 -> V_10 ) ;
F_26 ( & V_8 -> V_17 ) ;
F_20 ( & V_8 -> V_17 ) ;
F_27 ( & V_8 -> V_13 ) ;
F_27 ( & V_8 -> V_19 ) ;
}
void F_28 ( struct V_7 * V_8 )
{
V_8 -> V_40 = true ;
F_29 ( & V_8 -> V_41 ) ;
}
int F_30 ( struct V_7 * V_8 )
{
int V_9 ;
F_31 ( & V_8 -> V_42 ) ;
if ( V_8 -> V_43 < 0 ) {
V_9 = - V_44 ;
goto V_30;
}
if ( V_8 -> V_43 ++ == 0 )
F_28 ( V_8 ) ;
V_9 = 0 ;
V_30:
F_32 ( & V_8 -> V_42 ) ;
return V_9 ;
}
void F_33 ( struct V_7 * V_8 )
{
F_31 ( & V_8 -> V_42 ) ;
if ( F_34 ( V_8 -> V_43 <= 0 ) )
goto V_30;
if ( -- V_8 -> V_43 == 0 )
F_28 ( V_8 ) ;
V_30:
F_32 ( & V_8 -> V_42 ) ;
}
