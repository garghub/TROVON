int F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
struct V_7 * V_8 ;
int V_9 ;
V_8 = F_2 ( sizeof( * V_8 ) ,
V_3 ? V_10 : V_11 ) ;
if ( ! V_8 )
return - V_12 ;
if ( V_3 ) {
if ( ! F_3 ( & V_5 -> V_13 ) ) {
V_9 = - V_14 ;
goto V_15;
}
} else {
F_4 ( & V_5 -> V_13 ) ;
}
F_5 ( V_8 , 0 ) ;
V_8 -> V_16 = V_3 ;
V_17:
V_9 = F_6 ( & V_5 -> V_18 , V_8 ) ;
if ( V_9 )
goto V_19;
V_9 = F_7 ( V_2 , V_8 ) ;
if ( V_9 )
goto V_19;
F_8 ( V_5 -> V_20 ) ;
V_5 -> V_20 = V_8 ;
F_9 ( V_2 ) ;
return 0 ;
V_19:
if ( V_9 == - V_21 ) {
F_10 ( V_8 ) ;
goto V_17;
}
V_15:
F_11 ( V_8 ) ;
return V_9 ;
}
void F_12 ( struct V_1 * V_2 )
{
F_8 ( F_1 ( V_2 , false ) != 0 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_20 ;
if ( F_8 ( ! V_8 ) )
return;
V_5 -> V_20 = NULL ;
F_14 ( V_8 ) ;
F_15 ( V_8 ) ;
F_11 ( V_8 ) ;
F_16 ( & V_2 -> V_6 . V_13 ) ;
}
void F_17 ( struct V_22 * V_23 ,
struct V_24 * V_25 )
{
struct V_7 * V_8 ;
int V_9 ;
V_8 = F_2 ( sizeof( * V_8 ) , V_11 ) ;
if ( F_8 ( ! V_8 ) )
return;
F_5 ( V_8 , 0 ) ;
V_17:
V_9 = F_6 ( & V_23 -> V_13 , V_8 ) ;
if ( V_9 )
goto V_19;
if ( V_25 ) {
V_9 = F_6 ( & V_25 -> V_13 , V_8 ) ;
if ( V_9 )
goto V_19;
if ( V_25 -> V_23 ) {
V_9 = F_6 ( & V_25 -> V_23 -> V_13 , V_8 ) ;
if ( V_9 )
goto V_19;
}
}
F_8 ( V_23 -> V_20 ) ;
V_23 -> V_20 = V_8 ;
return;
V_19:
if ( V_9 == - V_21 ) {
F_10 ( V_8 ) ;
goto V_17;
}
}
struct V_7 *
F_18 ( struct V_22 * V_23 )
{
if ( V_23 -> V_20 )
return V_23 -> V_20 ;
F_8 ( ! V_23 -> V_2 -> V_6 . V_20 ) ;
return V_23 -> V_2 -> V_6 . V_20 ;
}
void F_19 ( struct V_22 * V_23 )
{
struct V_7 * V_8 = V_23 -> V_20 ;
if ( F_8 ( ! V_8 ) )
return;
V_23 -> V_20 = NULL ;
F_14 ( V_8 ) ;
F_15 ( V_8 ) ;
F_11 ( V_8 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
if ( V_26 )
return;
F_20 (crtc, &dev->mode_config.crtc_list, head)
F_8 ( ! F_21 ( & V_23 -> V_13 ) ) ;
F_8 ( ! F_21 ( & V_2 -> V_6 . V_18 ) ) ;
F_8 ( ! F_22 ( & V_2 -> V_6 . V_13 ) ) ;
}
void F_5 ( struct V_7 * V_8 ,
T_1 V_27 )
{
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
F_23 ( & V_8 -> V_28 , & V_29 ) ;
F_24 ( & V_8 -> V_30 ) ;
}
void F_15 ( struct V_7 * V_8 )
{
F_25 ( & V_8 -> V_28 ) ;
}
void F_14 ( struct V_7 * V_8 )
{
F_8 ( V_8 -> V_31 ) ;
while ( ! F_26 ( & V_8 -> V_30 ) ) {
struct F_6 * V_32 ;
V_32 = F_27 ( & V_8 -> V_30 ,
struct F_6 , V_33 ) ;
F_28 ( V_32 ) ;
}
}
static inline int F_29 ( struct F_6 * V_32 ,
struct V_7 * V_8 ,
bool V_34 , bool V_35 )
{
int V_9 ;
F_8 ( V_8 -> V_31 ) ;
if ( V_8 -> V_16 ) {
if ( ! F_30 ( & V_32 -> V_13 ) )
return - V_14 ;
else
return 0 ;
} else if ( V_34 && V_35 ) {
V_9 = F_31 ( & V_32 -> V_13 , & V_8 -> V_28 ) ;
} else if ( V_34 ) {
V_9 = F_32 ( & V_32 -> V_13 , & V_8 -> V_28 ) ;
} else if ( V_35 ) {
F_33 ( & V_32 -> V_13 , & V_8 -> V_28 ) ;
V_9 = 0 ;
} else {
V_9 = F_34 ( & V_32 -> V_13 , & V_8 -> V_28 ) ;
}
if ( ! V_9 ) {
F_8 ( ! F_26 ( & V_32 -> V_33 ) ) ;
F_35 ( & V_32 -> V_33 , & V_8 -> V_30 ) ;
} else if ( V_9 == - V_36 ) {
V_9 = 0 ;
} else if ( V_9 == - V_21 ) {
V_8 -> V_31 = V_32 ;
}
return V_9 ;
}
static int F_36 ( struct V_7 * V_8 ,
bool V_34 )
{
struct F_6 * V_31 = V_8 -> V_31 ;
V_8 -> V_31 = NULL ;
if ( F_8 ( ! V_31 ) )
return 0 ;
F_14 ( V_8 ) ;
return F_29 ( V_31 , V_8 , V_34 , true ) ;
}
void F_10 ( struct V_7 * V_8 )
{
F_36 ( V_8 , false ) ;
}
int F_37 ( struct V_7 * V_8 )
{
return F_36 ( V_8 , true ) ;
}
int F_6 ( struct F_6 * V_32 ,
struct V_7 * V_8 )
{
if ( V_8 )
return F_29 ( V_32 , V_8 , false , false ) ;
F_34 ( & V_32 -> V_13 , NULL ) ;
return 0 ;
}
int F_38 ( struct F_6 * V_32 ,
struct V_7 * V_8 )
{
if ( V_8 )
return F_29 ( V_32 , V_8 , true , false ) ;
return F_32 ( & V_32 -> V_13 , NULL ) ;
}
void F_28 ( struct F_6 * V_32 )
{
F_39 ( & V_32 -> V_33 ) ;
F_40 ( & V_32 -> V_13 ) ;
}
int F_7 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
int V_9 = 0 ;
F_20 (crtc, &config->crtc_list, head) {
V_9 = F_6 ( & V_23 -> V_13 , V_8 ) ;
if ( V_9 )
return V_9 ;
}
F_20 (plane, &config->plane_list, head) {
V_9 = F_6 ( & V_25 -> V_13 , V_8 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
