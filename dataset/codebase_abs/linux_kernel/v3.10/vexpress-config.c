struct V_1 * F_1 (
struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_6 ;
int V_7 ;
F_2 ( L_1 , V_5 -> V_8 ) ;
F_3 ( & V_9 ) ;
V_7 = F_4 ( V_10 ,
F_5 ( V_11 ) ) ;
if ( V_7 >= F_5 ( V_11 ) ) {
F_6 ( L_2 ) ;
F_7 ( & V_9 ) ;
return NULL ;
}
F_8 ( V_7 , V_10 ) ;
V_6 = & V_11 [ V_7 ] ;
V_6 -> V_3 = V_3 ;
V_6 -> V_5 = V_5 ;
F_9 ( & V_6 -> V_12 ) ;
F_10 ( & V_6 -> V_13 ) ;
F_7 ( & V_9 ) ;
return V_6 ;
}
void F_11 ( struct V_1 * V_6 )
{
struct V_1 V_14 = * V_6 ;
int V_7 ;
F_3 ( & V_9 ) ;
for ( V_7 = 0 ; V_7 < F_5 ( V_11 ) ; V_7 ++ )
if ( & V_11 [ V_7 ] == V_6 )
F_12 ( V_7 , V_10 ) ;
F_7 ( & V_9 ) ;
F_13 ( ! F_14 ( & V_14 . V_12 ) ) ;
while ( ! F_14 ( & V_14 . V_12 ) )
F_15 () ;
}
struct V_15 * F_16 ( struct V_16 * V_17 ,
struct V_2 * V_3 )
{
struct V_2 * V_18 ;
struct V_15 * V_19 ;
int V_7 ;
if ( F_13 ( V_17 && V_3 && V_17 -> V_20 != V_3 ) )
return NULL ;
if ( V_17 && ! V_3 )
V_3 = V_17 -> V_20 ;
V_19 = F_17 ( sizeof( * V_19 ) , V_21 ) ;
if ( ! V_19 )
return NULL ;
V_18 = F_18 ( V_3 ) ;
while ( V_18 ) {
const T_1 * V_22 = F_19 ( V_18 ,
L_3 , NULL ) ;
if ( V_22 ) {
V_18 = F_20 (
F_21 ( V_22 ) ) ;
break;
}
V_18 = F_22 ( V_18 ) ;
}
F_3 ( & V_9 ) ;
for ( V_7 = 0 ; V_7 < F_5 ( V_11 ) ; V_7 ++ ) {
struct V_1 * V_6 =
& V_11 [ V_7 ] ;
if ( F_23 ( V_7 , V_10 ) &&
V_6 -> V_3 == V_18 ) {
V_19 -> V_6 = V_6 ;
V_19 -> V_19 = V_6 -> V_5 -> V_23 ( V_17 , V_3 ) ;
break;
}
}
F_7 ( & V_9 ) ;
if ( ! V_19 -> V_19 ) {
F_24 ( V_3 ) ;
F_25 ( V_19 ) ;
return NULL ;
}
return V_19 ;
}
void F_26 ( struct V_15 * V_19 )
{
V_19 -> V_6 -> V_5 -> V_24 ( V_19 -> V_19 ) ;
F_24 ( V_19 -> V_6 -> V_3 ) ;
F_25 ( V_19 ) ;
}
static void F_27 ( const char * V_25 ,
struct V_26 * V_27 )
{
F_2 ( L_4 ,
V_25 , V_27 -> V_28 ? L_5 : L_6 , V_27 ,
V_27 -> V_19 -> V_19 , V_27 -> V_29 ,
V_27 -> V_30 ? * V_27 -> V_30 : 0 , V_27 -> V_31 ) ;
}
static int F_28 ( struct V_26 * V_27 )
{
int V_31 ;
struct V_1 * V_6 = V_27 -> V_19 -> V_6 ;
unsigned long V_32 ;
F_29 ( & V_27 -> V_33 ) ;
V_27 -> V_31 = - V_34 ;
F_30 ( & V_6 -> V_13 , V_32 ) ;
if ( F_14 ( & V_6 -> V_12 ) ) {
F_27 ( L_7 , V_27 ) ;
V_31 = V_6 -> V_5 -> V_35 ( V_27 -> V_19 -> V_19 ,
V_27 -> V_29 , V_27 -> V_28 , V_27 -> V_30 ) ;
} else {
F_27 ( L_8 , V_27 ) ;
V_31 = V_36 ;
}
switch ( V_31 ) {
case V_37 :
F_27 ( L_9 , V_27 ) ;
V_27 -> V_31 = V_31 ;
break;
case V_36 :
F_31 ( & V_27 -> V_38 , & V_6 -> V_12 ) ;
break;
}
F_32 ( & V_6 -> V_13 , V_32 ) ;
return V_31 ;
}
void F_33 ( struct V_1 * V_6 ,
int V_31 )
{
struct V_26 * V_27 ;
unsigned long V_32 ;
const char * V_39 = L_10 ;
F_30 ( & V_6 -> V_13 , V_32 ) ;
V_27 = F_34 ( & V_6 -> V_12 ,
struct V_26 , V_38 ) ;
V_27 -> V_31 = V_31 ;
do {
F_27 ( V_39 , V_27 ) ;
F_35 ( & V_27 -> V_38 ) ;
F_36 ( & V_27 -> V_33 ) ;
if ( F_14 ( & V_6 -> V_12 ) )
break;
V_27 = F_34 ( & V_6 -> V_12 ,
struct V_26 , V_38 ) ;
F_27 ( L_11 , V_27 ) ;
V_27 -> V_31 = V_6 -> V_5 -> V_35 ( V_27 -> V_19 -> V_19 ,
V_27 -> V_29 , V_27 -> V_28 , V_27 -> V_30 ) ;
V_39 = L_12 ;
} while ( V_27 -> V_31 == V_37 );
F_32 ( & V_6 -> V_13 , V_32 ) ;
}
int F_37 ( struct V_26 * V_27 )
{
F_38 ( & V_27 -> V_33 ) ;
return V_27 -> V_31 ;
}
int F_39 ( struct V_15 * V_19 , int V_29 ,
T_2 * V_30 )
{
struct V_26 V_27 = {
. V_19 = V_19 ,
. V_29 = V_29 ,
. V_28 = false ,
. V_30 = V_30 ,
. V_31 = 0 ,
} ;
int V_31 = F_28 ( & V_27 ) ;
if ( V_31 == V_36 )
V_31 = F_37 ( & V_27 ) ;
return V_31 ;
}
int F_40 ( struct V_15 * V_19 , int V_29 ,
T_2 V_30 )
{
struct V_26 V_27 = {
. V_19 = V_19 ,
. V_29 = V_29 ,
. V_28 = true ,
. V_30 = & V_30 ,
. V_31 = 0 ,
} ;
int V_31 = F_28 ( & V_27 ) ;
if ( V_31 == V_36 )
V_31 = F_37 ( & V_27 ) ;
return V_31 ;
}
