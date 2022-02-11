static inline void F_1 ( struct V_1 * V_2 , int V_3 )
{
V_2 -> V_4 [ V_3 ] &= ~ V_5 ;
}
static inline void F_2 ( struct V_1 * V_2 , int V_3 )
{
V_2 -> V_4 [ V_3 ] |= V_5 ;
}
static inline void F_3 ( struct V_1 * V_2 , int V_3 )
{
V_2 -> V_4 [ V_3 ] &= ~ V_6 ;
}
static inline void F_4 ( struct V_1 * V_2 , int V_3 )
{
V_2 -> V_4 [ V_3 ] |= V_6 ;
}
static inline bool F_5 ( struct V_1 * V_2 , int V_3 )
{
return V_2 -> V_4 [ V_3 ] & V_5 ;
}
static inline bool F_6 ( struct V_1 * V_2 , int V_3 )
{
return V_2 -> V_4 [ V_3 ] & V_6 ;
}
static T_1 F_7 ( struct V_7 * V_8 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_1 * V_2 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_10 ) ;
int V_3 = V_13 -> V_14 ;
bool V_15 = V_13 -> V_16 ;
int V_17 ;
if ( F_10 ( & V_2 -> V_18 ) )
return - V_19 ;
V_17 = F_6 ( V_2 , V_3 ) ?
V_2 -> V_20 : V_2 -> V_20 / 2 ;
if ( V_15 ) {
if ( F_5 ( V_2 , V_3 ) )
V_17 = - V_17 ;
else
V_17 = 0 ;
}
F_11 ( & V_2 -> V_18 ) ;
return sprintf ( V_11 , L_1 , V_17 ) ;
}
static T_1 F_12 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
const char * V_11 , T_2 V_21 )
{
struct V_1 * V_2 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_10 ) ;
int V_3 = V_13 -> V_14 ;
bool V_15 = V_13 -> V_16 ;
long V_22 ;
int V_23 = V_2 -> V_20 / 2 ;
int V_24 = V_2 -> V_20 ;
if ( F_13 ( V_11 , 10 , & V_22 ) )
return - V_25 ;
if ( V_15 ) {
if ( V_22 <= - V_24 )
V_22 = - V_24 ;
else if ( V_22 < 0 )
V_22 = - V_23 ;
else
V_22 = 0 ;
} else {
if ( V_22 >= V_24 )
V_22 = V_24 ;
else
V_22 = V_23 ;
}
if ( F_10 ( & V_2 -> V_18 ) )
return - V_19 ;
if ( V_22 == 0 ) {
F_1 ( V_2 , V_3 ) ;
} else if ( V_22 == - V_23 ) {
F_2 ( V_2 , V_3 ) ;
F_3 ( V_2 , V_3 ) ;
} else if ( V_22 == - V_24 ) {
F_2 ( V_2 , V_3 ) ;
F_4 ( V_2 , V_3 ) ;
} else if ( V_22 == V_23 ) {
F_3 ( V_2 , V_3 ) ;
} else if ( V_22 == V_24 ) {
F_4 ( V_2 , V_3 ) ;
}
F_11 ( & V_2 -> V_18 ) ;
return V_21 ;
}
static T_1 F_14 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
char * V_11 )
{
struct V_1 * V_2 = F_8 ( V_8 ) ;
struct V_26 * V_13 = F_15 ( V_10 ) ;
int V_3 = V_13 -> V_14 ;
T_3 V_22 ;
int V_27 ;
if ( F_10 ( & V_2 -> V_18 ) )
return - V_19 ;
V_27 = V_2 -> V_28 -> V_29 ( V_2 -> V_4 [ V_3 ] ) ;
if ( V_27 < 0 ) {
F_16 ( V_8 , L_2 ) ;
goto V_30;
}
V_22 = V_27 ;
if ( V_2 -> V_31 ) {
V_22 *= V_32 ;
if ( F_6 ( V_2 , V_3 ) )
V_22 *= 2 ;
V_22 /= 10000 ;
}
V_27 = sprintf ( V_11 , L_1 , V_22 ) ;
V_30:
F_11 ( & V_2 -> V_18 ) ;
return V_27 ;
}
static T_1 F_17 ( struct V_7 * V_8 ,
struct V_9 * V_13 , char * V_11 )
{
struct V_33 * V_34 = F_18 ( V_8 ) ;
return sprintf ( V_11 , L_3 , V_34 -> V_35 ) ;
}
static int F_19 ( struct V_33 * V_34 )
{
int V_36 , V_27 ;
struct V_1 * V_2 ;
struct V_37 * V_28 = F_20 ( & V_34 -> V_8 ) ;
enum V_38 V_39 = F_21 ( V_34 ) -> V_40 ;
if ( V_28 == NULL ) {
F_16 ( & V_34 -> V_8 , L_4 ) ;
return - V_25 ;
}
if ( V_28 -> V_29 == NULL ) {
F_16 ( & V_34 -> V_8 , L_5 ) ;
return - V_25 ;
}
V_2 = F_22 ( & V_34 -> V_8 , sizeof( struct V_1 ) , V_41 ) ;
if ( ! V_2 ) {
F_16 ( & V_34 -> V_8 , L_6 ) ;
return - V_42 ;
}
V_2 -> V_28 = V_28 ;
F_23 ( & V_2 -> V_18 ) ;
if ( V_39 == V_43 ) {
V_2 -> V_20 = V_44 ;
V_2 -> V_31 = true ;
} else {
V_2 -> V_20 = V_45 ;
V_2 -> V_31 = false ;
}
for ( V_36 = 0 ; V_36 < V_46 ; V_36 ++ )
V_2 -> V_4 [ V_36 ] = ( V_47 ) V_36 ;
F_24 ( V_34 , V_2 ) ;
V_27 = F_25 ( & V_34 -> V_8 . V_48 , & V_49 ) ;
if ( V_27 ) {
F_16 ( & V_34 -> V_8 , L_7 ) ;
return V_27 ;
}
V_2 -> V_50 = F_26 ( & V_34 -> V_8 ) ;
if ( F_27 ( V_2 -> V_50 ) ) {
V_27 = F_28 ( V_2 -> V_50 ) ;
F_16 ( & V_34 -> V_8 , L_8 ) ;
goto error;
}
return 0 ;
error:
F_29 ( & V_34 -> V_8 . V_48 , & V_49 ) ;
return V_27 ;
}
static int F_30 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = F_31 ( V_34 ) ;
F_32 ( V_2 -> V_50 ) ;
F_29 ( & V_34 -> V_8 . V_48 , & V_49 ) ;
return 0 ;
}
