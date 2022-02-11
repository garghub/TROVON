static void F_1 ( unsigned long V_1 , T_1 V_2 , T_1 V_3 ,
unsigned long * V_4 , T_1 V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_3 ; V_6 ++ , V_1 += V_5 )
F_2 ( V_4 , V_1 , V_2 ) ;
}
static int F_3 ( T_1 V_2 , unsigned long * V_1 , unsigned long * V_4 ,
T_2 V_7 )
{
unsigned long V_8 = 0 ;
unsigned long V_9 ;
bool V_10 = false ;
* V_1 = V_7 - V_2 ;
while ( V_8 < V_7 ) {
V_9 = F_4 ( V_4 , V_7 , * V_1 ) ;
if ( V_9 - * V_1 >= V_2 ) {
F_5 ( V_4 , * V_1 , V_2 ) ;
V_10 = true ;
break;
}
V_8 = V_7 - V_9 + V_2 ;
* V_1 = V_9 - V_2 ;
}
return ( V_10 ) ? 0 : - V_11 ;
}
static int F_6 ( T_1 V_2 , T_1 V_3 , T_1 V_12 , T_3 V_13 ,
unsigned long * V_1 , unsigned long V_14 ,
unsigned long * V_4 , T_2 V_7 , T_2 V_15 )
{
int V_6 ;
unsigned long V_16 ;
bool V_17 ;
unsigned long V_18 = V_19 / V_14 ;
unsigned long V_20 = ( V_13 > 0 ) ? V_13 / V_14 : 0 ;
unsigned long V_21 = V_20 ;
V_12 = ( V_13 > 0 ) ? 0 : V_12 - 1 ;
while ( V_21 < V_7 ) {
* V_1 = F_7 ( V_4 , V_7 , V_21 , V_2 ,
V_12 ) ;
if ( V_20 > 0 && ( * V_1 % V_18 != V_20 ) ) {
V_21 = F_8 ( * V_1 , V_18 ) + V_20 ;
continue;
}
if ( ( * V_1 % V_15 ) + V_2 > V_15 ) {
V_21 = F_8 ( * V_1 , V_15 ) + V_20 ;
continue;
}
if ( ( * V_1 + V_15 * V_3 ) > V_7 )
break;
F_2 ( V_22 , 0 , V_15 ) ;
F_5 ( V_22 , ( * V_1 % V_23 ) , V_2 ) ;
V_17 = true ;
for ( V_6 = 1 ; V_6 < V_3 ; V_6 ++ ) {
V_16 = * V_1 / V_23 + V_6 * 8 ;
if ( F_9 ( & V_4 [ V_16 ] , V_22 ,
( * V_1 % V_23 ) + V_2 ) ) {
V_17 = false ;
break;
}
}
if ( V_17 )
break;
if ( V_20 > 0 )
V_21 = F_8 ( * V_1 , V_18 ) + V_20 ;
else
V_21 = * V_1 + V_12 + 1 ;
}
if ( V_17 ) {
for ( V_6 = 0 , V_16 = * V_1 ; V_6 < V_3 ; V_6 ++ , V_16 += V_15 )
F_5 ( V_4 , V_16 , V_2 ) ;
}
return ( V_17 ) ? 0 : - V_11 ;
}
static T_4 F_10 ( struct V_24 * V_24 , T_5 V_25 ,
struct V_26 * V_27 )
{
unsigned long V_1 ;
int V_28 ;
F_11 ( & ( V_24 -> V_29 ) ) ;
V_28 = F_3 ( V_25 , & V_1 , V_24 -> V_30 , V_24 -> V_31 ) ;
if ( ! V_28 ) {
V_27 -> V_32 . V_33 = V_1 % V_24 -> V_34 ;
V_27 -> V_32 . V_35 = V_1 / V_24 -> V_34 ;
V_27 -> V_36 . V_33 = ( V_1 + V_25 - 1 ) % V_24 -> V_34 ;
V_27 -> V_36 . V_35 = ( V_1 + V_25 - 1 ) / V_24 -> V_34 ;
}
F_12 ( & ( V_24 -> V_29 ) ) ;
return V_28 ;
}
static T_4 F_13 ( struct V_24 * V_24 , T_6 V_3 , T_6 V_2 , T_6 V_37 ,
T_3 V_13 , T_1 V_14 ,
struct V_26 * V_27 )
{
unsigned long V_1 ;
int V_28 ;
F_11 ( & ( V_24 -> V_29 ) ) ;
V_28 = F_6 ( V_2 , V_3 , V_37 , V_13 , & V_1 , V_14 , V_24 -> V_30 ,
V_24 -> V_31 , V_24 -> V_34 ) ;
if ( ! V_28 ) {
V_27 -> V_32 . V_33 = V_1 % V_24 -> V_34 ;
V_27 -> V_32 . V_35 = V_1 / V_24 -> V_34 ;
V_27 -> V_36 . V_33 = V_27 -> V_32 . V_33 + V_2 - 1 ;
V_27 -> V_36 . V_35 = V_27 -> V_32 . V_35 + V_3 - 1 ;
}
F_12 ( & ( V_24 -> V_29 ) ) ;
return V_28 ;
}
static void F_14 ( struct V_24 * V_24 )
{
F_15 ( V_24 ) ;
}
static T_4 F_16 ( struct V_24 * V_24 , struct V_26 * V_27 )
{
unsigned long V_1 ;
T_1 V_2 , V_3 ;
V_1 = V_27 -> V_32 . V_33 + V_27 -> V_32 . V_35 * V_24 -> V_34 ;
if ( V_27 -> V_38 ) {
V_2 = V_27 -> V_36 . V_33 - V_27 -> V_32 . V_33 + 1 ;
V_3 = V_27 -> V_36 . V_35 - V_27 -> V_32 . V_35 + 1 ;
} else {
V_2 = V_27 -> V_36 . V_33 + V_27 -> V_36 . V_35 * V_24 -> V_34 - V_1 + 1 ;
V_3 = 1 ;
}
F_11 ( & ( V_24 -> V_29 ) ) ;
F_1 ( V_1 , V_2 , V_3 , V_24 -> V_30 , V_24 -> V_34 ) ;
F_12 ( & ( V_24 -> V_29 ) ) ;
return 0 ;
}
struct V_24 * F_17 ( T_6 V_34 , T_6 V_39 )
{
struct V_24 * V_24 ;
T_2 V_31 = F_18 ( V_34 * V_39 ) * sizeof( unsigned long ) ;
if ( V_34 == 0 || V_39 == 0 )
return NULL ;
V_24 = F_19 ( sizeof( * V_24 ) + V_31 , V_40 ) ;
if ( ! V_24 )
goto error;
V_24 -> V_39 = V_39 ;
V_24 -> V_34 = V_34 ;
V_24 -> V_41 = F_13 ;
V_24 -> V_42 = F_10 ;
V_24 -> free = F_16 ;
V_24 -> V_43 = F_14 ;
F_20 ( & V_24 -> V_29 ) ;
V_24 -> V_30 = ( unsigned long * ) ( V_24 + 1 ) ;
F_2 ( V_24 -> V_30 , 0 , V_34 * V_39 ) ;
V_24 -> V_31 = V_34 * V_39 ;
return V_24 ;
error:
F_15 ( V_24 ) ;
return NULL ;
}
