static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_5 ;
T_1 V_6 ;
T_2 * V_7 ;
int V_8 , V_9 ;
V_4 = F_2 ( sizeof( struct V_3 ) , V_10 ) ;
if ( V_4 == NULL ) {
return - V_11 ;
}
F_3 ( & V_4 -> free ) ;
F_3 ( & V_4 -> V_12 ) ;
V_4 -> V_13 = 0 ;
V_8 = F_4 ( V_2 , 0 , & V_4 -> V_14 , V_15 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_16 , L_1 ) ;
F_6 ( V_4 ) ;
return V_8 ;
}
V_6 = V_2 -> V_17 . V_18 . V_6 ;
V_6 += V_4 -> V_14 -> V_19 . V_20 ;
V_7 = V_2 -> V_17 . V_18 . V_7 ;
V_7 += ( V_4 -> V_14 -> V_19 . V_20 >> 2 ) ;
for ( V_9 = 0 ; V_9 < ( V_15 / 8 ) ; V_9 ++ ) {
V_4 -> V_21 [ V_9 ] . V_6 = V_6 ;
V_4 -> V_21 [ V_9 ] . V_7 = V_7 ;
V_4 -> V_21 [ V_9 ] . V_4 = V_4 ;
F_7 ( & V_4 -> V_21 [ V_9 ] . V_12 , & V_4 -> free ) ;
V_6 += 8 ;
V_7 += 2 ;
}
F_8 ( & V_2 -> V_22 . V_23 , V_5 ) ;
F_7 ( & V_4 -> V_12 , & V_2 -> V_22 . V_4 ) ;
F_9 ( & V_2 -> V_22 . V_23 , V_5 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_11 ( V_2 , & V_4 -> V_14 -> V_19 ) ;
F_12 ( & V_4 -> V_14 -> V_24 ) ;
F_13 ( & V_4 -> V_12 ) ;
F_6 ( V_4 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_25 ;
if ( F_15 ( & V_2 -> V_22 . V_4 ) ) {
return;
}
V_4 = F_16 ( & V_2 -> V_22 . V_4 , struct V_3 , V_12 ) ;
if ( F_15 ( & V_4 -> free ) ) {
return;
}
F_17 (bo, n, &rdev->semaphore_drv.bo, list) {
if ( V_4 -> V_13 )
continue;
F_10 ( V_2 , V_4 ) ;
}
}
int F_18 ( struct V_1 * V_2 ,
struct V_26 * * V_27 )
{
struct V_3 * V_4 ;
unsigned long V_5 ;
bool V_28 = true ;
int V_8 ;
V_29:
* V_27 = NULL ;
F_8 ( & V_2 -> V_22 . V_23 , V_5 ) ;
F_19 (bo, &rdev->semaphore_drv.bo, list) {
if ( F_15 ( & V_4 -> free ) )
continue;
* V_27 = F_16 ( & V_4 -> free , struct V_26 , V_12 ) ;
( * V_27 ) -> V_7 [ 0 ] = 0 ;
( * V_27 ) -> V_7 [ 1 ] = 0 ;
F_13 ( & ( * V_27 ) -> V_12 ) ;
V_4 -> V_13 ++ ;
break;
}
F_9 ( & V_2 -> V_22 . V_23 , V_5 ) ;
if ( * V_27 == NULL ) {
if ( V_28 ) {
V_28 = false ;
V_8 = F_1 ( V_2 ) ;
if ( V_8 )
return V_8 ;
goto V_29;
}
return - V_11 ;
}
return 0 ;
}
void F_20 ( struct V_1 * V_2 , int V_30 ,
struct V_26 * V_27 )
{
F_21 ( V_2 , V_30 , & V_2 -> V_30 [ V_30 ] , V_27 , false ) ;
}
void F_22 ( struct V_1 * V_2 , int V_30 ,
struct V_26 * V_27 )
{
F_21 ( V_2 , V_30 , & V_2 -> V_30 [ V_30 ] , V_27 , true ) ;
}
void F_23 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
unsigned long V_5 ;
F_8 ( & V_2 -> V_22 . V_23 , V_5 ) ;
V_27 -> V_4 -> V_13 -- ;
F_7 ( & V_27 -> V_12 , & V_27 -> V_4 -> free ) ;
F_14 ( V_2 ) ;
F_9 ( & V_2 -> V_22 . V_23 , V_5 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_25 ;
unsigned long V_5 ;
F_8 ( & V_2 -> V_22 . V_23 , V_5 ) ;
F_25 (bo, n, &rdev->semaphore_drv.bo, list) {
if ( ! F_15 ( & V_4 -> free ) ) {
F_5 ( V_2 -> V_16 , L_2 ) ;
}
F_10 ( V_2 , V_4 ) ;
}
F_9 ( & V_2 -> V_22 . V_23 , V_5 ) ;
}
