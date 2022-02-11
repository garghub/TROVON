void F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_2 ( & V_2 -> V_4 , & V_5 ) ;
F_3 ( & V_2 -> V_6 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_4 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_7 ) ;
while ( ! F_8 ( & V_2 -> V_6 ) ) {
struct V_8 * V_9 ;
V_9 = F_9 ( & V_2 -> V_6 ,
struct V_8 , V_10 ) ;
F_10 ( V_9 ) ;
}
}
static inline int F_11 ( struct V_8 * V_9 ,
struct V_1 * V_2 ,
bool V_11 , bool V_12 )
{
int V_13 ;
F_7 ( V_2 -> V_7 ) ;
if ( V_11 && V_12 ) {
V_13 = F_12 ( & V_9 -> V_14 , & V_2 -> V_4 ) ;
} else if ( V_11 ) {
V_13 = F_13 ( & V_9 -> V_14 , & V_2 -> V_4 ) ;
} else if ( V_12 ) {
F_14 ( & V_9 -> V_14 , & V_2 -> V_4 ) ;
V_13 = 0 ;
} else {
V_13 = F_15 ( & V_9 -> V_14 , & V_2 -> V_4 ) ;
}
if ( ! V_13 ) {
F_7 ( ! F_8 ( & V_9 -> V_10 ) ) ;
F_16 ( & V_9 -> V_10 , & V_2 -> V_6 ) ;
} else if ( V_13 == - V_15 ) {
V_13 = 0 ;
} else if ( V_13 == - V_16 ) {
V_2 -> V_7 = V_9 ;
}
return V_13 ;
}
static int F_17 ( struct V_1 * V_2 ,
bool V_11 )
{
struct V_8 * V_7 = V_2 -> V_7 ;
V_2 -> V_7 = NULL ;
if ( F_7 ( ! V_7 ) )
return 0 ;
F_6 ( V_2 ) ;
return F_11 ( V_7 , V_2 , V_11 , true ) ;
}
void F_18 ( struct V_1 * V_2 )
{
F_17 ( V_2 , false ) ;
}
int F_19 ( struct V_1 * V_2 )
{
return F_17 ( V_2 , true ) ;
}
int V_8 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
if ( V_2 )
return F_11 ( V_9 , V_2 , false , false ) ;
F_15 ( & V_9 -> V_14 , NULL ) ;
return 0 ;
}
int F_20 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
if ( V_2 )
return F_11 ( V_9 , V_2 , true , false ) ;
return F_13 ( & V_9 -> V_14 , NULL ) ;
}
void F_10 ( struct V_8 * V_9 )
{
F_21 ( & V_9 -> V_10 ) ;
F_22 ( & V_9 -> V_14 ) ;
}
int F_23 ( struct V_17 * V_18 ,
struct V_1 * V_2 )
{
struct V_19 * V_20 = & V_18 -> V_21 ;
struct V_22 * V_23 ;
int V_13 = 0 ;
F_24 (crtc, &config->crtc_list, head) {
V_13 = V_8 ( & V_23 -> V_14 , V_2 ) ;
if ( V_13 )
return V_13 ;
}
return 0 ;
}
