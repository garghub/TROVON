int F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
int V_4 ;
F_2 ( & V_5 ) ;
if ( V_2 -> V_6 ) {
F_3 ( L_1 ,
V_2 -> V_6 -> V_7 ) ;
V_4 = - V_8 ;
goto V_9;
}
if ( V_2 -> V_10 != V_3 -> type ) {
F_3 ( L_2 ) ;
V_4 = - V_8 ;
goto V_9;
}
V_2 -> V_6 = V_3 ;
V_3 -> V_11 = V_2 ;
F_4 ( & V_5 ) ;
return 0 ;
V_9:
F_4 ( & V_5 ) ;
return V_4 ;
}
int F_5 ( struct V_1 * V_2 )
{
int V_4 ;
F_2 ( & V_5 ) ;
if ( ! V_2 -> V_6 ) {
F_3 ( L_3 ) ;
V_4 = - V_8 ;
goto V_9;
}
if ( V_2 -> V_6 -> V_12 != V_13 ) {
F_3 ( L_4 ,
V_2 -> V_6 -> V_7 ) ;
V_4 = - V_8 ;
goto V_9;
}
V_2 -> V_6 -> V_11 = NULL ;
V_2 -> V_6 = NULL ;
F_4 ( & V_5 ) ;
return 0 ;
V_9:
F_4 ( & V_5 ) ;
return V_4 ;
}
int F_6 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_14 , & V_15 ) ;
return 0 ;
}
void F_8 ( struct V_1 * V_2 )
{
F_9 ( & V_2 -> V_14 ) ;
}
struct V_1 * F_10 ( enum V_16 V_17 )
{
struct V_1 * V_2 ;
F_11 (out, &output_list, list) {
if ( V_2 -> V_17 == V_17 )
return V_2 ;
}
return NULL ;
}
struct V_1 * F_12 ( const char * V_7 )
{
struct V_1 * V_2 ;
F_11 (out, &output_list, list) {
if ( strcmp ( V_2 -> V_7 , V_7 ) == 0 )
return F_13 ( V_2 ) ;
}
return NULL ;
}
struct V_1 * F_14 ( struct V_18 * V_19 )
{
struct V_18 * V_20 ;
struct V_1 * V_2 ;
T_1 V_21 ;
V_20 = F_15 ( V_19 ) ;
if ( ! V_20 )
return NULL ;
V_21 = F_16 ( V_19 ) ;
F_11 (out, &output_list, list) {
if ( V_2 -> V_22 -> V_23 == V_20 && V_2 -> V_24 == V_21 ) {
F_17 ( V_20 ) ;
return F_13 ( V_2 ) ;
}
}
F_17 ( V_20 ) ;
return NULL ;
}
struct V_1 * F_18 ( struct V_1 * V_3 )
{
while ( V_3 -> V_11 )
V_3 = V_3 -> V_11 ;
if ( V_3 -> V_17 != 0 )
return F_13 ( V_3 ) ;
return NULL ;
}
struct V_25 * F_19 ( struct V_1 * V_3 )
{
struct V_1 * V_2 ;
struct V_25 * V_26 ;
V_2 = F_18 ( V_3 ) ;
if ( V_2 == NULL )
return NULL ;
V_26 = V_2 -> V_27 ;
F_20 ( V_2 ) ;
return V_26 ;
}
int F_21 ( const struct V_28 * V_29 )
{
if ( V_28 )
return - V_30 ;
V_28 = V_29 ;
return 0 ;
}
void F_22 ( void )
{
V_28 = NULL ;
}
int F_23 ( struct V_25 * V_26 ,
struct V_1 * V_6 )
{
return V_28 -> V_31 ( V_26 , V_6 ) ;
}
void F_24 ( struct V_25 * V_26 ,
struct V_1 * V_6 )
{
V_28 -> V_32 ( V_26 , V_6 ) ;
}
void F_25 ( struct V_25 * V_26 ,
const struct V_33 * V_34 )
{
V_28 -> V_35 ( V_26 , V_34 ) ;
}
void F_26 ( struct V_25 * V_26 ,
const struct V_36 * V_37 )
{
V_28 -> V_38 ( V_26 , V_37 ) ;
}
int F_27 ( struct V_25 * V_26 )
{
return V_28 -> V_39 ( V_26 ) ;
}
void F_28 ( struct V_25 * V_26 )
{
V_28 -> V_40 ( V_26 ) ;
}
void F_29 ( struct V_25 * V_26 )
{
V_28 -> V_41 ( V_26 ) ;
}
int F_30 ( struct V_25 * V_26 ,
void (* F_31)( void * ) , void * V_42 )
{
return V_28 -> V_43 ( V_26 , F_31 , V_42 ) ;
}
void F_32 ( struct V_25 * V_26 ,
void (* F_31)( void * ) , void * V_42 )
{
V_28 -> V_44 ( V_26 , F_31 , V_42 ) ;
}
