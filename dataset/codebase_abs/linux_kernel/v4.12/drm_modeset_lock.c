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
void F_10 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
if ( V_16 )
return;
F_14 (crtc, dev)
F_3 ( ! F_15 ( & V_15 -> V_10 ) ) ;
F_3 ( ! F_15 ( & V_2 -> V_5 . V_17 ) ) ;
F_3 ( ! F_16 ( & V_2 -> V_5 . V_10 ) ) ;
}
void F_5 ( struct V_6 * V_7 ,
T_1 V_18 )
{
memset ( V_7 , 0 , sizeof( * V_7 ) ) ;
F_17 ( & V_7 -> V_19 , & V_20 ) ;
F_18 ( & V_7 -> V_21 ) ;
}
void F_8 ( struct V_6 * V_7 )
{
F_19 ( & V_7 -> V_19 ) ;
}
void F_12 ( struct V_6 * V_7 )
{
F_3 ( V_7 -> V_22 ) ;
while ( ! F_20 ( & V_7 -> V_21 ) ) {
struct V_23 * V_24 ;
V_24 = F_21 ( & V_7 -> V_21 ,
struct V_23 , V_25 ) ;
F_22 ( V_24 ) ;
}
}
static inline int F_23 ( struct V_23 * V_24 ,
struct V_6 * V_7 ,
bool V_26 , bool V_27 )
{
int V_8 ;
F_3 ( V_7 -> V_22 ) ;
if ( V_7 -> V_28 ) {
F_24 ( & V_7 -> V_19 ) ;
if ( ! F_25 ( & V_24 -> V_10 ) )
return - V_29 ;
else
return 0 ;
} else if ( V_26 && V_27 ) {
V_8 = F_26 ( & V_24 -> V_10 , & V_7 -> V_19 ) ;
} else if ( V_26 ) {
V_8 = F_27 ( & V_24 -> V_10 , & V_7 -> V_19 ) ;
} else if ( V_27 ) {
F_28 ( & V_24 -> V_10 , & V_7 -> V_19 ) ;
V_8 = 0 ;
} else {
V_8 = F_29 ( & V_24 -> V_10 , & V_7 -> V_19 ) ;
}
if ( ! V_8 ) {
F_3 ( ! F_20 ( & V_24 -> V_25 ) ) ;
F_30 ( & V_24 -> V_25 , & V_7 -> V_21 ) ;
} else if ( V_8 == - V_30 ) {
V_8 = 0 ;
} else if ( V_8 == - V_12 ) {
V_7 -> V_22 = V_24 ;
}
return V_8 ;
}
static int F_31 ( struct V_6 * V_7 ,
bool V_26 )
{
struct V_23 * V_22 = V_7 -> V_22 ;
V_7 -> V_22 = NULL ;
if ( F_3 ( ! V_22 ) )
return 0 ;
F_12 ( V_7 ) ;
return F_23 ( V_22 , V_7 , V_26 , true ) ;
}
void F_7 ( struct V_6 * V_7 )
{
F_31 ( V_7 , false ) ;
}
int F_32 ( struct V_6 * V_7 )
{
return F_31 ( V_7 , true ) ;
}
void F_33 ( struct V_23 * V_24 )
{
F_34 ( & V_24 -> V_10 , & V_20 ) ;
F_18 ( & V_24 -> V_25 ) ;
}
int V_23 ( struct V_23 * V_24 ,
struct V_6 * V_7 )
{
if ( V_7 )
return F_23 ( V_24 , V_7 , false , false ) ;
F_29 ( & V_24 -> V_10 , NULL ) ;
return 0 ;
}
int F_35 ( struct V_23 * V_24 ,
struct V_6 * V_7 )
{
if ( V_7 )
return F_23 ( V_24 , V_7 , true , false ) ;
return F_27 ( & V_24 -> V_10 , NULL ) ;
}
void F_22 ( struct V_23 * V_24 )
{
F_36 ( & V_24 -> V_25 ) ;
F_37 ( & V_24 -> V_10 ) ;
}
int F_6 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_14 * V_15 ;
struct V_31 * V_32 ;
int V_8 ;
V_8 = V_23 ( & V_2 -> V_5 . V_17 , V_7 ) ;
if ( V_8 )
return V_8 ;
F_14 (crtc, dev) {
V_8 = V_23 ( & V_15 -> V_10 , V_7 ) ;
if ( V_8 )
return V_8 ;
}
F_38 (plane, dev) {
V_8 = V_23 ( & V_32 -> V_10 , V_7 ) ;
if ( V_8 )
return V_8 ;
}
return 0 ;
}
