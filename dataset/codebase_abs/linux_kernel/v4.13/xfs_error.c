static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_4 *
F_3 ( struct V_5 * V_5 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
return F_2 ( V_7 , struct V_4 , V_8 ) ;
}
STATIC T_1
F_5 (
struct V_5 * V_5 ,
struct V_2 * V_3 ,
const char * V_9 ,
T_2 V_10 )
{
struct V_4 * V_11 = F_3 ( V_5 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
int V_13 ;
unsigned int V_14 ;
if ( strcmp ( V_9 , L_1 ) == 0 ) {
V_14 = V_15 [ V_12 -> V_16 ] ;
} else {
V_13 = F_6 ( V_9 , 0 , & V_14 ) ;
if ( V_13 )
return V_13 ;
}
V_13 = F_7 ( V_11 , V_12 -> V_16 , V_14 ) ;
if ( V_13 )
return V_13 ;
return V_10 ;
}
STATIC T_1
F_8 (
struct V_5 * V_5 ,
struct V_2 * V_3 ,
char * V_9 )
{
struct V_4 * V_11 = F_3 ( V_5 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
return snprintf ( V_9 , V_17 , L_2 ,
F_9 ( V_11 , V_12 -> V_16 ) ) ;
}
int
F_10 (
struct V_4 * V_11 )
{
V_11 -> V_18 = F_11 ( sizeof( unsigned int ) * V_19 ,
V_20 | V_21 ) ;
if ( ! V_11 -> V_18 )
return - V_22 ;
return F_12 ( & V_11 -> V_8 , & V_23 ,
& V_11 -> V_24 , L_3 ) ;
}
void
F_13 (
struct V_4 * V_11 )
{
F_14 ( & V_11 -> V_8 ) ;
F_15 ( V_11 -> V_18 ) ;
}
bool
F_16 (
struct V_4 * V_11 ,
const char * V_25 ,
const char * V_26 ,
int line ,
unsigned int V_27 )
{
unsigned int V_28 ;
if ( ! V_11 -> V_18 )
return false ;
ASSERT ( V_27 < V_19 ) ;
V_28 = V_11 -> V_18 [ V_27 ] ;
if ( ! V_28 || F_17 () % V_28 )
return false ;
F_18 ( V_11 ,
L_4 ,
V_25 , V_26 , line , V_11 -> V_29 ) ;
return true ;
}
int
F_9 (
struct V_4 * V_11 ,
unsigned int V_27 )
{
if ( V_27 >= V_19 )
return - V_30 ;
return V_11 -> V_18 [ V_27 ] ;
}
int
F_7 (
struct V_4 * V_11 ,
unsigned int V_27 ,
unsigned int V_31 )
{
if ( V_27 >= V_19 )
return - V_30 ;
V_11 -> V_18 [ V_27 ] = V_31 ;
return 0 ;
}
int
F_19 (
struct V_4 * V_11 ,
unsigned int V_27 )
{
if ( V_27 >= V_19 )
return - V_30 ;
return F_7 ( V_11 , V_27 ,
V_15 [ V_27 ] ) ;
}
int
F_20 (
struct V_4 * V_11 )
{
memset ( V_11 -> V_18 , 0 , sizeof( unsigned int ) * V_19 ) ;
return 0 ;
}
void
F_21 (
const char * V_16 ,
int V_32 ,
struct V_4 * V_11 ,
const char * V_33 ,
int V_34 ,
void * V_35 )
{
if ( V_32 <= V_36 ) {
F_22 ( V_11 , V_37 ,
L_5 ,
V_16 , V_34 , V_33 , V_35 ) ;
F_23 () ;
}
}
void
F_24 (
const char * V_16 ,
int V_32 ,
struct V_4 * V_11 ,
void * V_38 ,
const char * V_33 ,
int V_34 ,
void * V_35 )
{
if ( V_32 <= V_36 )
F_25 ( V_38 , 64 ) ;
F_21 ( V_16 , V_32 , V_11 , V_33 , V_34 , V_35 ) ;
F_26 ( V_11 , L_6 ) ;
}
void
F_27 (
struct V_39 * V_40 )
{
struct V_4 * V_11 = V_40 -> V_41 -> V_42 ;
F_26 ( V_11 , L_7 ,
V_40 -> V_43 == - V_44 ? L_8 : L_9 ,
V_45 , V_40 -> V_46 -> V_47 , V_40 -> V_48 ) ;
F_26 ( V_11 , L_10 ) ;
if ( V_36 >= V_49 ) {
F_26 ( V_11 , L_11 ) ;
F_25 ( F_28 ( V_40 , 0 ) , 64 ) ;
}
if ( V_36 >= V_50 )
F_23 () ;
}
