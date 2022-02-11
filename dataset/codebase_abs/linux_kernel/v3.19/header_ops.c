static int
F_1 ( T_1 * V_1 , const struct V_2 * V_3 ,
bool V_4 )
{
int V_5 = 0 ;
if ( V_3 -> V_6 == V_7 )
return 0 ;
if ( ! V_4 ) {
memcpy ( V_1 + V_5 , & V_3 -> V_8 , 2 ) ;
V_5 += 2 ;
}
switch ( V_3 -> V_6 ) {
case V_9 :
memcpy ( V_1 + V_5 , & V_3 -> V_10 , 2 ) ;
V_5 += 2 ;
break;
case V_11 :
memcpy ( V_1 + V_5 , & V_3 -> V_12 , V_13 ) ;
V_5 += V_13 ;
break;
default:
return - V_14 ;
}
return V_5 ;
}
static int
F_2 ( T_1 * V_1 , const struct V_15 * V_16 )
{
int V_5 = 5 ;
memcpy ( V_1 , V_16 , 1 ) ;
memcpy ( V_1 + 1 , & V_16 -> V_17 , 4 ) ;
switch ( V_16 -> V_18 ) {
case V_19 :
return V_5 ;
case V_20 :
break;
case V_21 :
memcpy ( V_1 + V_5 , & V_16 -> V_22 , 4 ) ;
V_5 += 4 ;
break;
case V_23 :
memcpy ( V_1 + V_5 , & V_16 -> V_24 , V_13 ) ;
V_5 += V_13 ;
break;
}
V_1 [ V_5 ++ ] = V_16 -> V_25 ;
return V_5 ;
}
int
F_3 ( struct V_26 * V_27 , const struct V_28 * V_16 )
{
T_1 V_1 [ V_29 ] ;
int V_5 = 2 ;
int V_30 ;
struct V_31 V_32 = V_16 -> V_32 ;
V_1 [ V_5 ++ ] = V_16 -> V_33 ;
V_32 . V_34 = V_16 -> V_35 . V_6 ;
V_30 = F_1 ( V_1 + V_5 , & V_16 -> V_35 , false ) ;
if ( V_30 < 0 )
return - V_14 ;
V_5 += V_30 ;
V_32 . V_36 = V_16 -> V_37 . V_6 ;
if ( V_16 -> V_37 . V_8 == V_16 -> V_35 . V_8 &&
V_16 -> V_35 . V_6 != V_7 )
V_32 . V_38 = true ;
V_30 = F_1 ( V_1 + V_5 , & V_16 -> V_37 , V_32 . V_38 ) ;
if ( V_30 < 0 )
return - V_14 ;
V_5 += V_30 ;
if ( V_32 . V_39 ) {
V_32 . V_40 = 1 ;
V_30 = F_2 ( V_1 + V_5 , & V_16 -> V_41 ) ;
if ( V_30 < 0 )
return - V_14 ;
V_5 += V_30 ;
}
memcpy ( V_1 , & V_32 , 2 ) ;
memcpy ( F_4 ( V_27 , V_5 ) , V_1 , V_5 ) ;
return V_5 ;
}
static int
F_5 ( const T_1 * V_1 , int V_6 , bool V_4 ,
struct V_2 * V_3 )
{
int V_5 = 0 ;
V_3 -> V_6 = V_6 ;
if ( V_6 == V_7 )
return 0 ;
if ( ! V_4 ) {
memcpy ( & V_3 -> V_8 , V_1 + V_5 , 2 ) ;
V_5 += 2 ;
}
if ( V_6 == V_9 ) {
memcpy ( & V_3 -> V_10 , V_1 + V_5 , 2 ) ;
return V_5 + 2 ;
} else {
memcpy ( & V_3 -> V_12 , V_1 + V_5 , V_13 ) ;
return V_5 + V_13 ;
}
}
static int F_6 ( int V_6 , bool V_4 )
{
int V_42 = V_4 ? 0 : 2 ;
switch ( V_6 ) {
case V_7 : return 0 ;
case V_9 : return 2 + V_42 ;
case V_11 : return V_13 + V_42 ;
default: return - V_14 ;
}
}
static int
F_7 ( const T_1 * V_1 , struct V_15 * V_16 )
{
int V_5 = 5 ;
memcpy ( V_16 , V_1 , 1 ) ;
memcpy ( & V_16 -> V_17 , V_1 + 1 , 4 ) ;
switch ( V_16 -> V_18 ) {
case V_19 :
return V_5 ;
case V_20 :
break;
case V_21 :
memcpy ( & V_16 -> V_22 , V_1 + V_5 , 4 ) ;
V_5 += 4 ;
break;
case V_23 :
memcpy ( & V_16 -> V_24 , V_1 + V_5 , V_13 ) ;
V_5 += V_13 ;
break;
}
V_16 -> V_25 = V_1 [ V_5 ++ ] ;
return V_5 ;
}
static int F_8 ( T_1 V_43 )
{
return V_44 [ F_9 ( V_43 ) ] ;
}
static int F_10 ( const struct V_28 * V_16 )
{
int V_45 , V_46 ;
V_45 = F_6 ( V_16 -> V_32 . V_34 , false ) ;
V_46 = F_6 ( V_16 -> V_32 . V_36 ,
V_16 -> V_32 . V_38 ) ;
if ( V_46 < 0 || V_45 < 0 )
return - V_14 ;
return 3 + V_45 + V_46 + V_16 -> V_32 . V_39 ;
}
static int
F_11 ( const T_1 * V_1 , struct V_28 * V_16 )
{
int V_5 = 0 ;
V_5 += F_5 ( V_1 + V_5 , V_16 -> V_32 . V_34 ,
false , & V_16 -> V_35 ) ;
V_5 += F_5 ( V_1 + V_5 , V_16 -> V_32 . V_36 ,
V_16 -> V_32 . V_38 , & V_16 -> V_37 ) ;
if ( V_16 -> V_32 . V_38 )
V_16 -> V_37 . V_8 = V_16 -> V_35 . V_8 ;
return V_5 ;
}
int
F_12 ( struct V_26 * V_27 , struct V_28 * V_16 )
{
int V_5 = 3 , V_30 ;
if ( ! F_13 ( V_27 , 3 ) )
return - V_14 ;
memcpy ( V_16 , V_27 -> V_47 , 3 ) ;
V_30 = F_10 ( V_16 ) ;
if ( V_30 < 0 || ! F_13 ( V_27 , V_30 ) )
return - V_14 ;
V_5 += F_11 ( V_27 -> V_47 + V_5 , V_16 ) ;
if ( V_16 -> V_32 . V_39 ) {
int V_48 = V_5 + F_8 ( V_27 -> V_47 [ V_5 ] ) ;
if ( ! F_13 ( V_27 , V_48 ) )
return - V_14 ;
V_5 += F_7 ( V_27 -> V_47 + V_5 , & V_16 -> V_41 ) ;
}
F_14 ( V_27 , V_5 ) ;
return V_5 ;
}
int
F_15 ( const struct V_26 * V_27 , struct V_28 * V_16 )
{
const T_1 * V_1 = F_16 ( V_27 ) ;
int V_5 = 3 , V_30 ;
if ( V_1 + 3 > F_17 ( V_27 ) )
return - V_14 ;
memcpy ( V_16 , V_1 , 3 ) ;
V_30 = F_10 ( V_16 ) ;
if ( V_30 < 0 || V_1 + V_30 > F_17 ( V_27 ) )
return - V_14 ;
V_5 += F_11 ( V_1 + V_5 , V_16 ) ;
return V_5 ;
}
int
F_18 ( const struct V_26 * V_27 , struct V_28 * V_16 )
{
const T_1 * V_1 = F_16 ( V_27 ) ;
int V_5 ;
V_5 = F_15 ( V_27 , V_16 ) ;
if ( V_5 < 0 )
return - V_14 ;
if ( V_16 -> V_32 . V_39 ) {
T_1 V_18 = F_9 ( * ( V_1 + V_5 ) ) ;
int V_48 = V_5 + V_44 [ V_18 ] ;
if ( V_1 + V_48 > F_17 ( V_27 ) )
return - V_14 ;
V_5 += F_7 ( V_1 + V_5 , & V_16 -> V_41 ) ;
}
return V_5 ;
}
int F_19 ( const struct V_28 * V_16 )
{
int V_49 = F_10 ( V_16 ) ;
if ( V_16 -> V_32 . V_39 ) {
V_49 += V_44 [ V_16 -> V_41 . V_18 ] - 1 ;
V_49 += F_20 ( & V_16 -> V_41 ) ;
}
return V_50 - V_49 - V_51 ;
}
