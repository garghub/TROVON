void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_6 * V_7 ;
int V_8 ;
V_7 = F_2 ( sizeof( * V_7 ) , V_9 ) ;
if ( F_3 ( ! V_7 ) )
return;
F_4 ( & V_4 -> V_10 ) ;
F_5 ( V_7 , 0 ) ;
V_11:
V_8 = F_6 ( V_2 , V_7 ) ;
if ( V_8 < 0 ) {
if ( V_8 == - V_12 ) {
F_7 ( V_7 ) ;
goto V_11;
}
F_8 ( V_7 ) ;
F_9 ( V_7 ) ;
return;
}
F_3 ( V_4 -> V_13 ) ;
V_4 -> V_13 = V_7 ;
F_10 ( V_2 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_13 ;
if ( F_3 ( ! V_7 ) )
return;
V_4 -> V_13 = NULL ;
F_12 ( V_7 ) ;
F_8 ( V_7 ) ;
F_9 ( V_7 ) ;
F_13 ( & V_2 -> V_5 . V_10 ) ;
}
void F_14 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_6 * V_7 ;
int V_8 ;
V_7 = F_2 ( sizeof( * V_7 ) , V_9 ) ;
if ( F_3 ( ! V_7 ) )
return;
F_5 ( V_7 , 0 ) ;
V_11:
V_8 = F_15 ( & V_15 -> V_10 , V_7 ) ;
if ( V_8 )
goto V_18;
if ( V_17 ) {
V_8 = F_15 ( & V_17 -> V_10 , V_7 ) ;
if ( V_8 )
goto V_18;
if ( V_17 -> V_15 ) {
V_8 = F_15 ( & V_17 -> V_15 -> V_10 , V_7 ) ;
if ( V_8 )
goto V_18;
}
}
F_3 ( V_15 -> V_13 ) ;
V_15 -> V_13 = V_7 ;
return;
V_18:
if ( V_8 == - V_12 ) {
F_7 ( V_7 ) ;
goto V_11;
}
}
struct V_6 *
F_16 ( struct V_14 * V_15 )
{
if ( V_15 -> V_13 )
return V_15 -> V_13 ;
F_3 ( ! V_15 -> V_2 -> V_5 . V_13 ) ;
return V_15 -> V_2 -> V_5 . V_13 ;
}
void F_17 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = V_15 -> V_13 ;
if ( F_3 ( ! V_7 ) )
return;
V_15 -> V_13 = NULL ;
F_12 ( V_7 ) ;
F_8 ( V_7 ) ;
F_9 ( V_7 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
if ( V_19 )
return;
F_18 (crtc, dev)
F_3 ( ! F_19 ( & V_15 -> V_10 ) ) ;
F_3 ( ! F_19 ( & V_2 -> V_5 . V_20 ) ) ;
F_3 ( ! F_20 ( & V_2 -> V_5 . V_10 ) ) ;
}
void F_5 ( struct V_6 * V_7 ,
T_1 V_21 )
{
memset ( V_7 , 0 , sizeof( * V_7 ) ) ;
F_21 ( & V_7 -> V_22 , & V_23 ) ;
F_22 ( & V_7 -> V_24 ) ;
}
void F_8 ( struct V_6 * V_7 )
{
F_23 ( & V_7 -> V_22 ) ;
}
void F_12 ( struct V_6 * V_7 )
{
F_3 ( V_7 -> V_25 ) ;
while ( ! F_24 ( & V_7 -> V_24 ) ) {
struct F_15 * V_26 ;
V_26 = F_25 ( & V_7 -> V_24 ,
struct F_15 , V_27 ) ;
F_26 ( V_26 ) ;
}
}
static inline int F_27 ( struct F_15 * V_26 ,
struct V_6 * V_7 ,
bool V_28 , bool V_29 )
{
int V_8 ;
F_3 ( V_7 -> V_25 ) ;
if ( V_7 -> V_30 ) {
F_28 ( & V_7 -> V_22 ) ;
if ( ! F_29 ( & V_26 -> V_10 ) )
return - V_31 ;
else
return 0 ;
} else if ( V_28 && V_29 ) {
V_8 = F_30 ( & V_26 -> V_10 , & V_7 -> V_22 ) ;
} else if ( V_28 ) {
V_8 = F_31 ( & V_26 -> V_10 , & V_7 -> V_22 ) ;
} else if ( V_29 ) {
F_32 ( & V_26 -> V_10 , & V_7 -> V_22 ) ;
V_8 = 0 ;
} else {
V_8 = F_33 ( & V_26 -> V_10 , & V_7 -> V_22 ) ;
}
if ( ! V_8 ) {
F_3 ( ! F_24 ( & V_26 -> V_27 ) ) ;
F_34 ( & V_26 -> V_27 , & V_7 -> V_24 ) ;
} else if ( V_8 == - V_32 ) {
V_8 = 0 ;
} else if ( V_8 == - V_12 ) {
V_7 -> V_25 = V_26 ;
}
return V_8 ;
}
static int F_35 ( struct V_6 * V_7 ,
bool V_28 )
{
struct F_15 * V_25 = V_7 -> V_25 ;
V_7 -> V_25 = NULL ;
if ( F_3 ( ! V_25 ) )
return 0 ;
F_12 ( V_7 ) ;
return F_27 ( V_25 , V_7 , V_28 , true ) ;
}
void F_7 ( struct V_6 * V_7 )
{
F_35 ( V_7 , false ) ;
}
int F_36 ( struct V_6 * V_7 )
{
return F_35 ( V_7 , true ) ;
}
void F_37 ( struct F_15 * V_26 )
{
F_38 ( & V_26 -> V_10 , & V_23 ) ;
F_22 ( & V_26 -> V_27 ) ;
}
int F_15 ( struct F_15 * V_26 ,
struct V_6 * V_7 )
{
if ( V_7 )
return F_27 ( V_26 , V_7 , false , false ) ;
F_33 ( & V_26 -> V_10 , NULL ) ;
return 0 ;
}
int F_39 ( struct F_15 * V_26 ,
struct V_6 * V_7 )
{
if ( V_7 )
return F_27 ( V_26 , V_7 , true , false ) ;
return F_31 ( & V_26 -> V_10 , NULL ) ;
}
void F_26 ( struct F_15 * V_26 )
{
F_40 ( & V_26 -> V_27 ) ;
F_41 ( & V_26 -> V_10 ) ;
}
int F_6 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_14 * V_15 ;
struct V_16 * V_17 ;
int V_8 ;
V_8 = F_15 ( & V_2 -> V_5 . V_20 , V_7 ) ;
if ( V_8 )
return V_8 ;
F_18 (crtc, dev) {
V_8 = F_15 ( & V_15 -> V_10 , V_7 ) ;
if ( V_8 )
return V_8 ;
}
F_42 (plane, dev) {
V_8 = F_15 ( & V_17 -> V_10 , V_7 ) ;
if ( V_8 )
return V_8 ;
}
return 0 ;
}
