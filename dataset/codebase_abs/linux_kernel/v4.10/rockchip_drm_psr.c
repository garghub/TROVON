static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
struct V_1 * V_8 ;
unsigned long V_9 ;
F_2 ( & V_5 -> V_10 , V_9 ) ;
F_3 (psr, &drm_drv->psr_list, list) {
if ( V_8 -> V_11 -> V_3 == V_3 )
goto V_12;
}
V_8 = F_4 ( - V_13 ) ;
V_12:
F_5 ( & V_5 -> V_10 , V_9 ) ;
return V_8 ;
}
static void F_6 ( struct V_1 * V_8 , enum V_14 V_15 )
{
if ( V_15 == V_8 -> V_15 || ! V_8 -> V_16 )
return;
if ( V_15 == V_17 && V_8 -> V_15 == V_18 ) {
V_8 -> V_15 = V_15 ;
return;
}
V_8 -> V_15 = V_15 ;
switch ( V_8 -> V_15 ) {
case V_19 :
V_8 -> V_20 ( V_8 -> V_11 , true ) ;
break;
case V_17 :
case V_18 :
V_8 -> V_20 ( V_8 -> V_11 , false ) ;
break;
}
}
static void F_7 ( struct V_1 * V_8 , enum V_14 V_15 )
{
unsigned long V_9 ;
F_2 ( & V_8 -> V_21 , V_9 ) ;
F_6 ( V_8 , V_15 ) ;
F_5 ( & V_8 -> V_21 , V_9 ) ;
}
static void F_8 ( unsigned long V_22 )
{
struct V_1 * V_8 = (struct V_1 * ) V_22 ;
unsigned long V_9 ;
F_2 ( & V_8 -> V_21 , V_9 ) ;
if ( V_8 -> V_15 == V_18 )
F_6 ( V_8 , V_19 ) ;
F_5 ( & V_8 -> V_21 , V_9 ) ;
}
int F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
unsigned long V_9 ;
if ( F_10 ( V_8 ) )
return F_11 ( V_8 ) ;
F_2 ( & V_8 -> V_21 , V_9 ) ;
V_8 -> V_16 = true ;
F_5 ( & V_8 -> V_21 , V_9 ) ;
return 0 ;
}
int F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
unsigned long V_9 ;
if ( F_10 ( V_8 ) )
return F_11 ( V_8 ) ;
F_2 ( & V_8 -> V_21 , V_9 ) ;
V_8 -> V_16 = false ;
F_5 ( & V_8 -> V_21 , V_9 ) ;
F_13 ( & V_8 -> V_23 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_8 )
{
F_15 ( & V_8 -> V_23 ,
F_16 ( V_24 + V_25 ) ) ;
F_7 ( V_8 , V_18 ) ;
}
int F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
if ( F_10 ( V_8 ) )
return F_11 ( V_8 ) ;
F_14 ( V_8 ) ;
return 0 ;
}
void F_18 ( struct V_26 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_1 * V_8 ;
unsigned long V_9 ;
F_2 ( & V_5 -> V_10 , V_9 ) ;
F_3 (psr, &drm_drv->psr_list, list)
F_14 ( V_8 ) ;
F_5 ( & V_5 -> V_10 , V_9 ) ;
}
int F_19 ( struct V_27 * V_11 ,
void (* F_20)( struct V_27 * , bool V_28 ) )
{
struct V_4 * V_5 = V_11 -> V_6 -> V_7 ;
struct V_1 * V_8 ;
unsigned long V_9 ;
if ( ! V_11 || ! F_20 )
return - V_29 ;
V_8 = F_21 ( sizeof( struct V_1 ) , V_30 ) ;
if ( ! V_8 )
return - V_31 ;
F_22 ( & V_8 -> V_23 , F_8 , ( unsigned long ) V_8 ) ;
F_23 ( & V_8 -> V_21 ) ;
V_8 -> V_16 = true ;
V_8 -> V_15 = V_17 ;
V_8 -> V_11 = V_11 ;
V_8 -> V_20 = F_20 ;
F_2 ( & V_5 -> V_10 , V_9 ) ;
F_24 ( & V_8 -> V_32 , & V_5 -> V_33 ) ;
F_5 ( & V_5 -> V_10 , V_9 ) ;
return 0 ;
}
void F_25 ( struct V_27 * V_11 )
{
struct V_4 * V_5 = V_11 -> V_6 -> V_7 ;
struct V_1 * V_8 , * V_34 ;
unsigned long V_9 ;
F_2 ( & V_5 -> V_10 , V_9 ) ;
F_26 (psr, n, &drm_drv->psr_list, list) {
if ( V_8 -> V_11 == V_11 ) {
F_27 ( & V_8 -> V_23 ) ;
F_28 ( & V_8 -> V_32 ) ;
F_29 ( V_8 ) ;
}
}
F_5 ( & V_5 -> V_10 , V_9 ) ;
}
