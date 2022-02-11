void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
if ( ! V_4 )
return;
F_2 ( & V_5 , V_3 ) ;
memset ( & V_2 -> V_6 , 0 , sizeof( V_2 -> V_6 ) ) ;
V_2 -> V_7 = 0 ;
F_3 ( & V_5 , V_3 ) ;
}
static void F_4 ( void )
{
unsigned long V_3 ;
F_2 ( & V_5 , V_3 ) ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
F_3 ( & V_5 , V_3 ) ;
}
static void T_1
F_5 ( struct V_1 * V_8 ,
struct V_6 * V_9 )
{
int V_10 = V_11 + 1 ;
int V_12 ;
if ( ! V_4 )
return;
if ( ! V_8 -> V_13 )
return;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ ) {
int V_14 , V_15 = 1 ;
if ( ! V_6 [ V_12 ] . V_16 [ 0 ] ) {
if ( V_10 > V_12 )
V_10 = V_12 ;
continue;
}
for ( V_14 = 0 ; V_14 < V_17 ; V_14 ++ ) {
unsigned long V_18 = V_9 -> V_16 [ V_14 ] ;
if ( V_6 [ V_12 ] . V_16 [ V_14 ] != V_18 ) {
V_15 = 0 ;
break;
}
if ( V_18 == 0 || V_18 == V_19 )
break;
}
if ( V_15 ) {
V_6 [ V_12 ] . V_20 ++ ;
V_6 [ V_12 ] . time += V_9 -> time ;
if ( V_9 -> time > V_6 [ V_12 ] . V_21 )
V_6 [ V_12 ] . V_21 = V_9 -> time ;
return;
}
}
V_12 = V_10 ;
if ( V_12 >= V_11 - 1 )
return;
memcpy ( & V_6 [ V_12 ] , V_9 , sizeof( struct V_6 ) ) ;
}
static inline void F_6 ( struct V_1 * V_8 ,
struct V_6 * V_9 )
{
struct V_22 V_23 ;
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
V_23 . V_24 = V_17 ;
V_23 . V_25 = & V_9 -> V_16 [ 0 ] ;
F_7 ( V_8 , & V_23 ) ;
}
void T_1
F_8 ( struct V_1 * V_8 , int V_26 , int V_27 )
{
unsigned long V_3 ;
int V_12 , V_14 ;
struct V_6 V_9 ;
if ( V_27 && V_26 > 5000 )
return;
if ( V_26 <= 0 )
return;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_20 = 1 ;
V_9 . time = V_26 ;
V_9 . V_21 = V_26 ;
F_6 ( V_8 , & V_9 ) ;
F_2 ( & V_5 , V_3 ) ;
F_5 ( V_8 , & V_9 ) ;
for ( V_12 = 0 ; V_12 < V_8 -> V_7 ; V_12 ++ ) {
struct V_6 * V_28 ;
int V_15 = 1 ;
V_28 = & V_8 -> V_6 [ V_12 ] ;
for ( V_14 = 0 ; V_14 < V_17 ; V_14 ++ ) {
unsigned long V_18 = V_9 . V_16 [ V_14 ] ;
if ( V_28 -> V_16 [ V_14 ] != V_18 ) {
V_15 = 0 ;
break;
}
if ( V_18 == 0 || V_18 == V_19 )
break;
}
if ( V_15 ) {
V_28 -> V_20 ++ ;
V_28 -> time += V_9 . time ;
if ( V_9 . time > V_28 -> V_21 )
V_28 -> V_21 = V_9 . time ;
goto V_29;
}
}
if ( V_8 -> V_7 >= V_30 )
goto V_29;
V_12 = V_8 -> V_7 ++ ;
memcpy ( & V_8 -> V_6 [ V_12 ] , & V_9 , sizeof( struct V_6 ) ) ;
V_29:
F_3 ( & V_5 , V_3 ) ;
}
static int F_9 ( struct V_31 * V_32 , void * V_33 )
{
int V_12 ;
F_10 ( V_32 , L_1 ) ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ ) {
struct V_6 * V_34 = & V_6 [ V_12 ] ;
if ( V_34 -> V_16 [ 0 ] ) {
int V_14 ;
F_11 ( V_32 , L_2 ,
V_34 -> V_20 , V_34 -> time , V_34 -> V_21 ) ;
for ( V_14 = 0 ; V_14 < V_17 ; V_14 ++ ) {
unsigned long V_35 = V_34 -> V_16 [ V_14 ] ;
if ( ! V_35 )
break;
if ( V_35 == V_19 )
break;
F_11 ( V_32 , L_3 , ( void * ) V_35 ) ;
}
F_10 ( V_32 , L_4 ) ;
}
}
return 0 ;
}
static T_2
F_12 ( struct V_36 * V_36 , const char T_3 * V_37 , T_4 V_20 ,
T_5 * V_38 )
{
F_4 () ;
return V_20 ;
}
static int F_13 ( struct V_39 * V_39 , struct V_36 * V_40 )
{
return F_14 ( V_40 , F_9 , NULL ) ;
}
static int T_6 F_15 ( void )
{
F_16 ( L_5 , 0644 , NULL , & V_41 ) ;
return 0 ;
}
