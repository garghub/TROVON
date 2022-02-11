void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
for ( V_4 = V_2 -> V_5 ; V_4 < V_2 -> V_6 ; V_4 ++ ) {
memset ( V_4 , 0 , sizeof( struct V_3 ) ) ;
V_4 -> V_7 = V_8 ;
V_4 -> V_9 = V_8 ;
V_4 -> V_10 = V_11 ;
}
}
void F_2 ( struct V_1 * V_2 , bool V_12 )
{
struct V_3 * V_4 ;
unsigned long V_13 ;
for ( V_4 = V_2 -> V_5 ; V_4 < V_2 -> V_6 ; V_4 ++ ) {
if ( V_4 -> V_7 != V_14 )
continue;
F_3 ( & V_2 -> V_15 , V_13 ) ;
F_4 ( V_2 , V_4 ) ;
F_5 ( & V_2 -> V_15 , V_13 ) ;
if ( V_12 ) {
F_6 ( L_1 , F_7 ( V_4 ,
V_2 ) ) ;
F_8 ( V_2 , F_7 ( V_4 ,
V_2 ) ,
V_8 ) ;
}
}
}
void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_13 ;
F_10 () ;
if ( F_11 ( V_16 , & V_2 -> V_13 ) ) {
F_12 () ;
return;
}
for ( V_4 = V_2 -> V_5 ; V_4 < V_2 -> V_6 ; V_4 ++ ) {
T_1 V_17 = V_11 ;
F_3 ( & V_2 -> V_15 , V_13 ) ;
if ( V_4 -> V_9 != V_4 -> V_7 )
V_17 = V_4 -> V_9 = V_4 -> V_7 ;
F_5 ( & V_2 -> V_15 , V_13 ) ;
if ( V_17 != V_11 ) {
F_6 ( L_2 ,
F_7 (
V_4 ,
V_2 ) ) ;
F_6 ( L_3 , V_17 ) ;
F_8 ( V_2 ,
F_7 ( V_4 ,
V_2 ) ,
V_17 ) ;
}
}
F_12 () ;
}
struct V_3 * F_13 ( struct V_1 * V_2 ,
struct V_18 *
V_19 )
{
struct V_3 * V_4 ;
F_10 () ;
if ( V_19 -> V_20 >= V_21 ) {
F_14 () ;
F_12 () ;
return NULL ;
}
V_4 = V_2 -> V_5 + V_19 -> V_20 ;
if ( V_4 -> V_7 == V_14 ) {
F_12 () ;
return NULL ;
}
F_15 ( L_4 , V_19 -> V_22 ,
F_7 (
V_4 ,
V_2 ) ) ;
if ( V_19 -> V_23 == 0
|| V_19 -> V_24 == 0 ) {
F_15 ( L_5 ) ;
F_12 () ;
return NULL ;
}
V_4 -> V_24 = V_19 -> V_24 ;
V_4 -> V_25 = V_19 -> V_23 ;
V_4 -> V_26 = V_19 -> V_23 / V_19 -> V_24 ;
V_4 -> V_27 = V_19 -> V_20 ;
V_4 -> V_28 = V_29 ;
V_4 -> V_13 &= ~ V_30 ;
V_4 -> V_13 |= V_31 ;
V_4 -> V_32 = 0 ;
V_4 -> V_7 = V_14 ;
return V_4 ;
}
struct V_3 * F_16 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
T_1 * V_33 ,
T_1 V_34 )
{
struct V_3 * V_4 ;
F_10 () ;
if ( V_19 -> V_20 >= V_21 ) {
F_14 () ;
F_12 () ;
return NULL ;
}
V_4 = F_17 ( V_2 , V_33 , V_34 ) ;
if ( V_4 == NULL ) {
V_4 = V_2 -> V_5 + V_19 -> V_20 ;
if ( V_34 > sizeof( V_4 -> V_35 )
|| V_4 -> V_7 == V_14 ) {
F_12 () ;
return NULL ;
}
}
F_15 ( L_6 , F_7 ( V_4 , V_2 ) ,
V_19 -> V_20 ,
V_19 -> V_36 ) ;
V_4 -> V_24 = 0 ;
V_4 -> V_25 = 0 ;
V_4 -> V_26 = 0 ;
V_4 -> V_27 = V_19 -> V_20 ;
V_4 -> V_28 = V_19 -> V_36 ;
V_4 -> V_32 = V_34 ;
memcpy ( V_4 -> V_35 , V_33 , V_34 ) ;
V_4 -> V_13 |= V_30 | V_31 ;
V_4 -> V_7 = V_14 ;
return V_4 ;
}
void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_10 () ;
V_4 -> V_7 = V_8 ;
F_6 ( L_1 , F_7 ( V_4 , V_2 ) ) ;
F_12 () ;
}
struct V_3 * F_18 ( struct V_1 * V_2 ,
T_2 * V_37 )
{
struct V_3 * V_4 ;
for ( V_4 = V_2 -> V_5 ; V_4 < V_2 -> V_6 ; V_4 ++ )
if ( V_4 -> V_37 == * V_37 )
return V_4 ;
return NULL ;
}
struct V_3 * F_17 ( struct V_1 * V_2 ,
void * V_35 ,
T_1 V_34 )
{
struct V_3 * V_4 ;
for ( V_4 = V_2 -> V_5 ; V_4 < V_2 -> V_6 ; V_4 ++ ) {
if ( V_34 == V_4 -> V_32
&& memcmp ( & V_4 -> V_35 [ 0 ] , V_35 ,
V_34 ) == 0 )
return V_4 ;
}
return NULL ;
}
T_3 F_19 ( struct V_1 * V_2 , T_3 V_38 )
{
T_3 V_39 = V_38 + 1 ;
while ( V_39 < V_21 ) {
struct V_3 * V_4 = V_2 -> V_5 + V_39 ;
if ( V_4 -> V_7 == V_14 )
break;
V_39 ++ ;
}
return V_39 ;
}
struct V_3 * F_20 ( struct V_1 * V_2 ,
T_3 V_40 )
{
struct V_3 * V_4 ;
for ( V_4 = V_2 -> V_5 ; V_4 < V_2 -> V_6 ; V_4 ++ ) {
if ( V_4 -> V_7 != V_14 )
continue;
if ( V_4 -> V_27 == V_40 )
return V_4 ;
}
return NULL ;
}
T_3 F_21 ( struct V_1 * V_2 )
{
T_3 V_41 = 0 ;
struct V_3 * V_4 ;
unsigned long V_13 ;
F_3 ( & V_2 -> V_15 , V_13 ) ;
for ( V_4 = V_2 -> V_5 ; V_4 < V_2 -> V_6 ; V_4 ++ )
if ( V_4 -> V_7 == V_14 )
V_41 ++ ;
F_5 ( & V_2 -> V_15 , V_13 ) ;
return V_41 ;
}
