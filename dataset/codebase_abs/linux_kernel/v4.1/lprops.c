static int F_1 ( struct V_1 * V_2 , int V_3 )
{
switch ( V_3 ) {
case V_4 :
return V_2 -> free ;
case V_5 :
return V_2 -> free + V_2 -> V_6 ;
default:
return V_2 -> V_6 ;
}
}
static void F_2 ( struct V_7 * V_8 , struct V_9 * V_10 ,
struct V_1 * V_2 , int V_3 )
{
int V_11 , V_12 , V_13 ;
V_13 = V_2 -> V_13 ;
if ( ! V_13 )
return;
V_11 = F_1 ( V_2 , V_3 ) ;
do {
int V_14 = ( V_13 - 1 ) / 2 ;
V_12 = F_1 ( V_10 -> V_15 [ V_14 ] , V_3 ) ;
if ( V_12 >= V_11 )
return;
V_10 -> V_15 [ V_14 ] -> V_13 = V_13 ;
V_10 -> V_15 [ V_13 ] = V_10 -> V_15 [ V_14 ] ;
V_10 -> V_15 [ V_14 ] = V_2 ;
V_2 -> V_13 = V_14 ;
V_13 = V_14 ;
} while ( V_13 );
}
static void F_3 ( struct V_7 * V_8 , struct V_9 * V_10 ,
struct V_1 * V_2 , int V_13 , int V_3 )
{
int V_11 , V_12 , V_16 , V_17 ;
V_11 = F_1 ( V_2 , V_3 ) ;
if ( V_13 ) {
int V_14 = ( V_13 - 1 ) / 2 ;
V_12 = F_1 ( V_10 -> V_15 [ V_14 ] , V_3 ) ;
if ( V_11 > V_12 ) {
while ( 1 ) {
V_10 -> V_15 [ V_14 ] -> V_13 = V_13 ;
V_10 -> V_15 [ V_13 ] = V_10 -> V_15 [ V_14 ] ;
V_10 -> V_15 [ V_14 ] = V_2 ;
V_2 -> V_13 = V_14 ;
V_13 = V_14 ;
if ( ! V_13 )
return;
V_14 = ( V_13 - 1 ) / 2 ;
V_12 = F_1 ( V_10 -> V_15 [ V_14 ] , V_3 ) ;
if ( V_11 <= V_12 )
return;
}
}
}
while ( 1 ) {
V_17 = V_13 * 2 + 1 ;
if ( V_17 >= V_10 -> V_18 )
return;
V_12 = F_1 ( V_10 -> V_15 [ V_17 ] , V_3 ) ;
if ( V_11 < V_12 ) {
if ( V_17 + 1 < V_10 -> V_18 ) {
V_16 = F_1 ( V_10 -> V_15 [ V_17 + 1 ] ,
V_3 ) ;
if ( V_16 > V_12 )
V_17 += 1 ;
}
V_10 -> V_15 [ V_17 ] -> V_13 = V_13 ;
V_10 -> V_15 [ V_13 ] = V_10 -> V_15 [ V_17 ] ;
V_10 -> V_15 [ V_17 ] = V_2 ;
V_2 -> V_13 = V_17 ;
V_13 = V_17 ;
continue;
}
V_17 += 1 ;
if ( V_17 >= V_10 -> V_18 )
return;
V_16 = F_1 ( V_10 -> V_15 [ V_17 ] , V_3 ) ;
if ( V_11 < V_16 ) {
V_10 -> V_15 [ V_17 ] -> V_13 = V_13 ;
V_10 -> V_15 [ V_13 ] = V_10 -> V_15 [ V_17 ] ;
V_10 -> V_15 [ V_17 ] = V_2 ;
V_2 -> V_13 = V_17 ;
V_13 = V_17 ;
continue;
}
return;
}
}
static int F_4 ( struct V_7 * V_8 , struct V_1 * V_2 ,
int V_3 )
{
struct V_9 * V_10 = & V_8 -> V_19 [ V_3 - 1 ] ;
if ( V_10 -> V_18 >= V_10 -> V_20 ) {
const int V_21 = V_22 / 2 - 1 ;
int V_17 , V_11 , V_12 ;
V_17 = ( ( ( V_23 ) V_2 >> 4 ) & V_21 ) + V_21 ;
F_5 ( V_17 >= V_21 ) ;
F_5 ( V_17 < V_22 ) ;
F_5 ( V_17 < V_10 -> V_18 ) ;
V_11 = F_1 ( V_2 , V_3 ) ;
V_12 = F_1 ( V_10 -> V_15 [ V_17 ] , V_3 ) ;
if ( V_11 > V_12 ) {
struct V_1 * V_24 ;
V_24 = V_10 -> V_15 [ V_17 ] ;
V_24 -> V_25 &= ~ V_26 ;
V_24 -> V_25 |= V_27 ;
F_6 ( & V_24 -> V_28 , & V_8 -> V_29 ) ;
V_2 -> V_13 = V_17 ;
V_10 -> V_15 [ V_17 ] = V_2 ;
F_2 ( V_8 , V_10 , V_2 , V_3 ) ;
F_7 ( V_8 , V_10 , V_3 , V_2 -> V_13 ) ;
return 1 ;
}
F_7 ( V_8 , V_10 , V_3 , - 1 ) ;
return 0 ;
} else {
V_2 -> V_13 = V_10 -> V_18 ++ ;
V_10 -> V_15 [ V_2 -> V_13 ] = V_2 ;
F_2 ( V_8 , V_10 , V_2 , V_3 ) ;
F_7 ( V_8 , V_10 , V_3 , V_2 -> V_13 ) ;
return 1 ;
}
}
static void F_8 ( struct V_7 * V_8 ,
struct V_1 * V_2 , int V_3 )
{
struct V_9 * V_10 ;
int V_13 = V_2 -> V_13 ;
V_10 = & V_8 -> V_19 [ V_3 - 1 ] ;
F_5 ( V_13 >= 0 && V_13 < V_10 -> V_18 ) ;
F_5 ( V_10 -> V_15 [ V_13 ] == V_2 ) ;
V_10 -> V_18 -= 1 ;
if ( V_13 < V_10 -> V_18 ) {
V_10 -> V_15 [ V_13 ] = V_10 -> V_15 [ V_10 -> V_18 ] ;
V_10 -> V_15 [ V_13 ] -> V_13 = V_13 ;
F_3 ( V_8 , V_10 , V_10 -> V_15 [ V_13 ] , V_13 , V_3 ) ;
}
F_7 ( V_8 , V_10 , V_3 , - 1 ) ;
}
static void F_9 ( struct V_7 * V_8 ,
struct V_1 * V_30 ,
struct V_1 * V_31 , int V_3 )
{
struct V_9 * V_10 ;
int V_13 = V_31 -> V_13 ;
V_10 = & V_8 -> V_19 [ V_3 - 1 ] ;
V_10 -> V_15 [ V_13 ] = V_31 ;
}
void F_10 ( struct V_7 * V_8 , struct V_1 * V_2 ,
int V_3 )
{
switch ( V_3 ) {
case V_32 :
case V_5 :
case V_4 :
if ( F_4 ( V_8 , V_2 , V_3 ) )
break;
V_3 = V_27 ;
case V_27 :
F_6 ( & V_2 -> V_28 , & V_8 -> V_29 ) ;
break;
case V_33 :
F_6 ( & V_2 -> V_28 , & V_8 -> V_34 ) ;
break;
case V_35 :
F_6 ( & V_2 -> V_28 , & V_8 -> V_36 ) ;
V_8 -> V_37 += 1 ;
break;
case V_38 :
F_6 ( & V_2 -> V_28 , & V_8 -> V_39 ) ;
break;
default:
F_5 ( 0 ) ;
}
V_2 -> V_25 &= ~ V_26 ;
V_2 -> V_25 |= V_3 ;
V_8 -> V_40 += 1 ;
F_5 ( V_8 -> V_40 <= V_8 -> V_41 ) ;
}
static void F_11 ( struct V_7 * V_8 ,
struct V_1 * V_2 , int V_3 )
{
switch ( V_3 ) {
case V_32 :
case V_5 :
case V_4 :
F_8 ( V_8 , V_2 , V_3 ) ;
break;
case V_35 :
V_8 -> V_37 -= 1 ;
F_5 ( V_8 -> V_37 >= 0 ) ;
case V_27 :
case V_33 :
case V_38 :
F_5 ( ! F_12 ( & V_2 -> V_28 ) ) ;
F_13 ( & V_2 -> V_28 ) ;
break;
default:
F_5 ( 0 ) ;
}
V_8 -> V_40 -= 1 ;
F_5 ( V_8 -> V_40 >= 0 ) ;
}
void F_14 ( struct V_7 * V_8 , struct V_1 * V_30 ,
struct V_1 * V_31 )
{
int V_3 ;
V_3 = V_31 -> V_25 & V_26 ;
switch ( V_3 ) {
case V_32 :
case V_5 :
case V_4 :
F_9 ( V_8 , V_30 , V_31 , V_3 ) ;
break;
case V_27 :
case V_33 :
case V_35 :
case V_38 :
F_15 ( & V_30 -> V_28 , & V_31 -> V_28 ) ;
break;
default:
F_5 ( 0 ) ;
}
}
void F_16 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
int V_3 = V_2 -> V_25 & V_26 ;
if ( V_3 != V_27 )
return;
V_3 = F_17 ( V_8 , V_2 ) ;
if ( V_3 == V_27 )
return;
F_11 ( V_8 , V_2 , V_27 ) ;
F_10 ( V_8 , V_2 , V_3 ) ;
}
int F_17 ( const struct V_7 * V_8 ,
const struct V_1 * V_2 )
{
if ( V_2 -> V_25 & V_42 )
return V_27 ;
if ( V_2 -> free == V_8 -> V_43 ) {
F_5 ( ! ( V_2 -> V_25 & V_44 ) ) ;
return V_33 ;
}
if ( V_2 -> free + V_2 -> V_6 == V_8 -> V_43 ) {
if ( V_2 -> V_25 & V_44 )
return V_38 ;
else
return V_35 ;
}
if ( V_2 -> V_25 & V_44 ) {
if ( V_2 -> V_6 + V_2 -> free >= V_8 -> V_45 )
return V_5 ;
} else {
if ( V_2 -> V_6 >= V_8 -> V_46 &&
V_2 -> V_6 > V_2 -> free )
return V_32 ;
if ( V_2 -> free > 0 )
return V_4 ;
}
return V_27 ;
}
static void F_18 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
int V_47 = V_2 -> V_25 & V_26 ;
int V_48 = F_17 ( V_8 , V_2 ) ;
if ( V_47 == V_48 ) {
struct V_9 * V_10 ;
if ( V_48 < 1 || V_48 > V_49 )
return;
V_10 = & V_8 -> V_19 [ V_48 - 1 ] ;
F_3 ( V_8 , V_10 , V_2 , V_2 -> V_13 , V_48 ) ;
} else {
F_11 ( V_8 , V_2 , V_47 ) ;
F_10 ( V_8 , V_2 , V_48 ) ;
}
}
int F_19 ( const struct V_7 * V_8 , int V_50 )
{
F_5 ( ! ( V_50 & 7 ) ) ;
if ( V_50 < V_8 -> V_51 )
return V_50 ;
if ( V_50 - V_8 -> V_51 < V_52 )
return V_50 - V_52 ;
return V_8 -> V_51 ;
}
static int F_20 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_53 * V_54 ;
int V_55 ;
V_55 = ( V_2 -> V_56 - V_8 -> V_57 ) & ( V_58 - 1 ) ;
V_54 = (struct V_53 * ) F_21 ( V_2 - V_55 ,
struct V_53 ,
V_2 [ 0 ] ) ;
return ! F_22 ( V_59 , & V_54 -> V_25 ) &&
F_22 ( V_60 , & V_54 -> V_25 ) ;
}
const struct V_1 * F_23 ( struct V_7 * V_8 ,
const struct V_1 * V_24 ,
int free , int V_6 , int V_25 ,
int V_61 )
{
struct V_1 * V_2 = (struct V_1 * ) V_24 ;
F_24 ( L_1 ,
V_2 -> V_56 , free , V_6 , V_25 ) ;
F_5 ( F_25 ( & V_8 -> V_62 ) ) ;
F_5 ( V_8 -> V_63 . V_64 >= 0 &&
V_8 -> V_63 . V_64 <= V_8 -> V_41 ) ;
F_5 ( V_8 -> V_37 >= 0 ) ;
F_5 ( V_8 -> V_37 <= V_8 -> V_41 ) ;
F_5 ( V_8 -> V_63 . V_65 >= 0 ) ;
F_5 ( V_8 -> V_63 . V_65 <= V_8 -> V_63 . V_64 ) ;
F_5 ( ! ( V_8 -> V_63 . V_66 & 7 ) && ! ( V_8 -> V_63 . V_67 & 7 ) ) ;
F_5 ( ! ( V_8 -> V_63 . V_68 & 7 ) && ! ( V_8 -> V_63 . V_69 & 7 ) ) ;
F_5 ( ! ( V_8 -> V_63 . V_70 & 7 ) ) ;
F_5 ( free == V_71 || free >= 0 ) ;
F_5 ( V_6 == V_71 || V_6 >= 0 ) ;
if ( ! F_20 ( V_8 , V_2 ) ) {
V_2 = F_26 ( V_8 , V_2 -> V_56 ) ;
if ( F_27 ( V_2 ) )
return V_2 ;
} else
F_5 ( V_2 == F_26 ( V_8 , V_2 -> V_56 ) ) ;
F_5 ( ! ( V_2 -> free & 7 ) && ! ( V_2 -> V_6 & 7 ) ) ;
F_28 ( & V_8 -> V_72 ) ;
if ( ( V_2 -> V_25 & V_42 ) && V_2 -> free == V_8 -> V_43 )
V_8 -> V_63 . V_65 -= 1 ;
if ( ! ( V_2 -> V_25 & V_44 ) ) {
int V_73 ;
V_73 = V_2 -> free + V_2 -> V_6 ;
if ( V_73 < V_8 -> V_46 )
V_8 -> V_63 . V_68 -= V_73 ;
else
V_8 -> V_63 . V_69 -= F_19 ( V_8 , V_73 ) ;
V_8 -> V_63 . V_70 -= V_8 -> V_43 - V_73 ;
}
if ( free != V_71 ) {
free = F_29 ( free , 8 ) ;
V_8 -> V_63 . V_66 += free - V_2 -> free ;
if ( free == V_8 -> V_43 ) {
if ( V_2 -> free != V_8 -> V_43 )
V_8 -> V_63 . V_64 += 1 ;
} else if ( V_2 -> free == V_8 -> V_43 )
V_8 -> V_63 . V_64 -= 1 ;
V_2 -> free = free ;
}
if ( V_6 != V_71 ) {
V_6 = F_29 ( V_6 , 8 ) ;
V_8 -> V_63 . V_67 += V_6 - V_2 -> V_6 ;
V_2 -> V_6 = V_6 ;
}
if ( V_25 != V_71 ) {
if ( ( V_2 -> V_25 & V_44 ) ) {
if ( ! ( V_25 & V_44 ) )
V_8 -> V_63 . V_74 -= 1 ;
} else if ( V_25 & V_44 )
V_8 -> V_63 . V_74 += 1 ;
V_2 -> V_25 = V_25 ;
}
if ( ! ( V_2 -> V_25 & V_44 ) ) {
int V_75 ;
V_75 = V_2 -> free + V_2 -> V_6 ;
if ( V_75 < V_8 -> V_46 )
V_8 -> V_63 . V_68 += V_75 ;
else
V_8 -> V_63 . V_69 += F_19 ( V_8 , V_75 ) ;
V_8 -> V_63 . V_70 += V_8 -> V_43 - V_75 ;
}
if ( ( V_2 -> V_25 & V_42 ) && V_2 -> free == V_8 -> V_43 )
V_8 -> V_63 . V_65 += 1 ;
F_18 ( V_8 , V_2 ) ;
V_8 -> V_61 += V_61 ;
F_30 ( & V_8 -> V_72 ) ;
return V_2 ;
}
void F_31 ( struct V_7 * V_8 , struct V_76 * V_63 )
{
F_28 ( & V_8 -> V_72 ) ;
memcpy ( V_63 , & V_8 -> V_63 , sizeof( struct V_76 ) ) ;
F_30 ( & V_8 -> V_72 ) ;
}
int F_32 ( struct V_7 * V_8 , int V_56 , int free , int V_6 ,
int V_77 , int V_78 , int V_61 )
{
int V_79 = 0 , V_25 ;
const struct V_1 * V_24 ;
F_33 ( V_8 ) ;
V_24 = F_26 ( V_8 , V_56 ) ;
if ( F_27 ( V_24 ) ) {
V_79 = F_34 ( V_24 ) ;
goto V_80;
}
V_25 = ( V_24 -> V_25 | V_77 ) & ~ V_78 ;
V_24 = F_23 ( V_8 , V_24 , free , V_6 , V_25 , V_61 ) ;
if ( F_27 ( V_24 ) )
V_79 = F_34 ( V_24 ) ;
V_80:
F_35 ( V_8 ) ;
if ( V_79 )
F_36 ( V_8 , L_2 ,
V_56 , V_79 ) ;
return V_79 ;
}
int F_37 ( struct V_7 * V_8 , int V_56 , int free , int V_6 ,
int V_77 , int V_78 )
{
int V_79 = 0 , V_25 ;
const struct V_1 * V_24 ;
F_33 ( V_8 ) ;
V_24 = F_26 ( V_8 , V_56 ) ;
if ( F_27 ( V_24 ) ) {
V_79 = F_34 ( V_24 ) ;
goto V_80;
}
V_25 = ( V_24 -> V_25 | V_77 ) & ~ V_78 ;
V_24 = F_23 ( V_8 , V_24 , free , V_24 -> V_6 + V_6 , V_25 , 0 ) ;
if ( F_27 ( V_24 ) )
V_79 = F_34 ( V_24 ) ;
V_80:
F_35 ( V_8 ) ;
if ( V_79 )
F_36 ( V_8 , L_3 ,
V_56 , V_79 ) ;
return V_79 ;
}
int F_38 ( struct V_7 * V_8 , int V_56 , struct V_1 * V_24 )
{
int V_79 = 0 ;
const struct V_1 * V_81 ;
F_33 ( V_8 ) ;
V_81 = F_39 ( V_8 , V_56 ) ;
if ( F_27 ( V_81 ) ) {
V_79 = F_34 ( V_81 ) ;
F_36 ( V_8 , L_4 ,
V_56 , V_79 ) ;
goto V_80;
}
memcpy ( V_24 , V_81 , sizeof( struct V_1 ) ) ;
V_80:
F_35 ( V_8 ) ;
return V_79 ;
}
const struct V_1 * F_40 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
F_5 ( F_25 ( & V_8 -> V_62 ) ) ;
V_10 = & V_8 -> V_19 [ V_4 - 1 ] ;
if ( V_10 -> V_18 == 0 )
return NULL ;
V_2 = V_10 -> V_15 [ 0 ] ;
F_5 ( ! ( V_2 -> V_25 & V_42 ) ) ;
F_5 ( ! ( V_2 -> V_25 & V_44 ) ) ;
return V_2 ;
}
const struct V_1 * F_41 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
F_5 ( F_25 ( & V_8 -> V_62 ) ) ;
if ( F_12 ( & V_8 -> V_34 ) )
return NULL ;
V_2 = F_42 ( V_8 -> V_34 . V_82 , struct V_1 , V_28 ) ;
F_5 ( ! ( V_2 -> V_25 & V_42 ) ) ;
F_5 ( ! ( V_2 -> V_25 & V_44 ) ) ;
F_5 ( V_2 -> free == V_8 -> V_43 ) ;
return V_2 ;
}
const struct V_1 * F_43 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
F_5 ( F_25 ( & V_8 -> V_62 ) ) ;
if ( F_12 ( & V_8 -> V_36 ) )
return NULL ;
V_2 = F_42 ( V_8 -> V_36 . V_82 , struct V_1 , V_28 ) ;
F_5 ( ! ( V_2 -> V_25 & V_42 ) ) ;
F_5 ( ! ( V_2 -> V_25 & V_44 ) ) ;
F_5 ( V_2 -> free + V_2 -> V_6 == V_8 -> V_43 ) ;
F_5 ( V_8 -> V_37 > 0 ) ;
return V_2 ;
}
const struct V_1 * F_44 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
F_5 ( F_25 ( & V_8 -> V_62 ) ) ;
if ( F_12 ( & V_8 -> V_39 ) )
return NULL ;
V_2 = F_42 ( V_8 -> V_39 . V_82 , struct V_1 , V_28 ) ;
F_5 ( ! ( V_2 -> V_25 & V_42 ) ) ;
F_5 ( ( V_2 -> V_25 & V_44 ) ) ;
F_5 ( V_2 -> free + V_2 -> V_6 == V_8 -> V_43 ) ;
return V_2 ;
}
int F_45 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
struct V_83 * V_55 ;
int V_84 , V_3 ;
if ( ! F_46 ( V_8 ) && ! F_47 ( V_8 ) )
return 0 ;
F_48 (lprops, &c->empty_list, list) {
if ( V_2 -> free != V_8 -> V_43 ) {
F_36 ( V_8 , L_5 ,
V_2 -> V_56 , V_2 -> free , V_2 -> V_6 ,
V_2 -> V_25 ) ;
return - V_85 ;
}
if ( V_2 -> V_25 & V_42 ) {
F_36 ( V_8 , L_6 ,
V_2 -> V_56 , V_2 -> free , V_2 -> V_6 ,
V_2 -> V_25 ) ;
return - V_85 ;
}
}
V_84 = 0 ;
F_48 (lprops, &c->freeable_list, list) {
if ( V_2 -> free + V_2 -> V_6 != V_8 -> V_43 ) {
F_36 ( V_8 , L_7 ,
V_2 -> V_56 , V_2 -> free , V_2 -> V_6 ,
V_2 -> V_25 ) ;
return - V_85 ;
}
if ( V_2 -> V_25 & V_42 ) {
F_36 ( V_8 , L_8 ,
V_2 -> V_56 , V_2 -> free , V_2 -> V_6 ,
V_2 -> V_25 ) ;
return - V_85 ;
}
V_84 += 1 ;
}
if ( V_84 != V_8 -> V_37 ) {
F_36 ( V_8 , L_9 , V_84 ,
V_8 -> V_37 ) ;
return - V_85 ;
}
V_84 = 0 ;
F_49 (pos, &c->idx_gc)
V_84 += 1 ;
if ( V_84 != V_8 -> V_61 ) {
F_36 ( V_8 , L_10 , V_84 ,
V_8 -> V_61 ) ;
return - V_85 ;
}
F_48 (lprops, &c->frdi_idx_list, list) {
if ( V_2 -> free + V_2 -> V_6 != V_8 -> V_43 ) {
F_36 ( V_8 , L_11 ,
V_2 -> V_56 , V_2 -> free , V_2 -> V_6 ,
V_2 -> V_25 ) ;
return - V_85 ;
}
if ( V_2 -> V_25 & V_42 ) {
F_36 ( V_8 , L_12 ,
V_2 -> V_56 , V_2 -> free , V_2 -> V_6 ,
V_2 -> V_25 ) ;
return - V_85 ;
}
if ( ! ( V_2 -> V_25 & V_44 ) ) {
F_36 ( V_8 , L_13 ,
V_2 -> V_56 , V_2 -> free , V_2 -> V_6 ,
V_2 -> V_25 ) ;
return - V_85 ;
}
}
for ( V_3 = 1 ; V_3 <= V_49 ; V_3 ++ ) {
struct V_9 * V_10 = & V_8 -> V_19 [ V_3 - 1 ] ;
for ( V_84 = 0 ; V_84 < V_10 -> V_18 ; V_84 ++ ) {
V_2 = V_10 -> V_15 [ V_84 ] ;
if ( ! V_2 ) {
F_36 ( V_8 , L_14 , V_3 ) ;
return - V_85 ;
}
if ( V_2 -> V_13 != V_84 ) {
F_36 ( V_8 , L_15 , V_3 ) ;
return - V_85 ;
}
if ( V_2 -> V_25 & V_42 ) {
F_36 ( V_8 , L_16 , V_3 ) ;
return - V_85 ;
}
}
}
return 0 ;
}
void F_7 ( struct V_7 * V_8 , struct V_9 * V_10 , int V_3 ,
int V_86 )
{
int V_84 = 0 , V_87 , V_79 = 0 ;
if ( ! F_46 ( V_8 ) && ! F_47 ( V_8 ) )
return;
for ( V_84 = 0 ; V_84 < V_10 -> V_18 ; V_84 ++ ) {
struct V_1 * V_2 = V_10 -> V_15 [ V_84 ] ;
struct V_1 * V_24 ;
if ( V_84 != V_86 )
if ( ( V_2 -> V_25 & V_26 ) != V_3 ) {
V_79 = 1 ;
goto V_80;
}
if ( V_2 -> V_13 != V_84 ) {
V_79 = 2 ;
goto V_80;
}
V_24 = F_39 ( V_8 , V_2 -> V_56 ) ;
if ( F_27 ( V_24 ) ) {
V_79 = 3 ;
goto V_80;
}
if ( V_2 != V_24 ) {
F_36 ( V_8 , L_17 ,
( V_23 ) V_2 , ( V_23 ) V_24 , V_2 -> V_56 ,
V_24 -> V_56 ) ;
V_79 = 4 ;
goto V_80;
}
for ( V_87 = 0 ; V_87 < V_84 ; V_87 ++ ) {
V_24 = V_10 -> V_15 [ V_87 ] ;
if ( V_24 == V_2 ) {
V_79 = 5 ;
goto V_80;
}
if ( V_24 -> V_56 == V_2 -> V_56 ) {
V_79 = 6 ;
goto V_80;
}
}
}
V_80:
if ( V_79 ) {
F_36 ( V_8 , L_18 , V_3 , V_84 , V_79 ) ;
F_50 () ;
F_51 ( V_8 , V_10 , V_3 ) ;
}
}
static int F_52 ( struct V_7 * V_8 ,
const struct V_1 * V_24 , int V_88 ,
struct V_76 * V_63 )
{
struct V_89 * V_90 ;
struct V_91 * V_92 ;
int V_3 , V_56 = V_24 -> V_56 , V_93 = 0 , V_94 = 0 , free , V_6 , V_95 ;
void * V_96 = NULL ;
V_3 = V_24 -> V_25 & V_26 ;
if ( V_3 != V_27 ) {
V_3 = F_17 ( V_8 , V_24 ) ;
if ( V_3 != ( V_24 -> V_25 & V_26 ) ) {
F_36 ( V_8 , L_19 ,
( V_24 -> V_25 & V_26 ) , V_3 ) ;
return - V_85 ;
}
}
if ( V_88 ) {
struct V_83 * V_28 = NULL ;
switch ( V_3 ) {
case V_33 :
V_28 = & V_8 -> V_34 ;
break;
case V_35 :
V_28 = & V_8 -> V_36 ;
break;
case V_38 :
V_28 = & V_8 -> V_39 ;
break;
case V_27 :
V_28 = & V_8 -> V_29 ;
break;
}
if ( V_28 ) {
struct V_1 * V_2 ;
int V_97 = 0 ;
F_48 (lprops, list, list) {
if ( V_2 == V_24 ) {
V_97 = 1 ;
break;
}
}
if ( ! V_97 ) {
F_36 ( V_8 , L_20 , V_3 ) ;
return - V_85 ;
}
}
}
if ( V_88 && V_3 > 0 && V_3 <= V_49 ) {
struct V_9 * V_10 = & V_8 -> V_19 [ V_3 - 1 ] ;
if ( ( V_24 -> V_13 != - 1 && V_10 -> V_15 [ V_24 -> V_13 ] -> V_56 != V_56 ) ||
V_24 != V_10 -> V_15 [ V_24 -> V_13 ] ) {
F_36 ( V_8 , L_21 , V_3 ) ;
return - V_85 ;
}
}
V_96 = F_53 ( V_8 -> V_43 , V_98 , V_99 ) ;
if ( ! V_96 )
return - V_100 ;
if ( V_24 -> free == V_8 -> V_43 ) {
V_63 -> V_64 += 1 ;
V_63 -> V_66 += V_8 -> V_43 ;
V_63 -> V_69 += F_19 ( V_8 , V_8 -> V_43 ) ;
return V_101 ;
}
if ( V_24 -> free + V_24 -> V_6 == V_8 -> V_43 &&
! ( V_24 -> V_25 & V_44 ) ) {
V_63 -> V_66 += V_24 -> free ;
V_63 -> V_67 += V_24 -> V_6 ;
V_63 -> V_69 += F_19 ( V_8 , V_8 -> V_43 ) ;
return V_101 ;
}
V_90 = F_54 ( V_8 , V_56 , 0 , V_96 , 0 ) ;
if ( F_27 ( V_90 ) ) {
V_95 = F_34 ( V_90 ) ;
if ( V_95 == - V_102 ) {
F_55 ( V_8 ) ;
F_56 ( V_8 , & V_8 -> V_103 ) ;
}
goto V_80;
}
V_93 = - 1 ;
F_48 (snod, &sleb->nodes, list) {
int V_97 , V_104 = 0 ;
F_57 () ;
if ( V_93 == - 1 )
V_93 = ( V_92 -> type == V_105 ) ? 1 : 0 ;
if ( V_93 && V_92 -> type != V_105 ) {
F_36 ( V_8 , L_22 ,
V_56 , V_92 -> V_106 ) ;
goto V_107;
}
if ( V_92 -> type == V_105 ) {
struct V_108 * V_109 = V_92 -> V_110 ;
F_58 ( V_8 , F_59 ( V_8 , V_109 ) , & V_92 -> V_111 ) ;
V_104 = F_60 ( V_109 -> V_104 ) ;
}
V_97 = F_61 ( V_8 , & V_92 -> V_111 , V_104 , V_56 ,
V_92 -> V_106 , V_93 ) ;
if ( V_97 ) {
if ( V_97 < 0 )
goto V_107;
V_94 += F_29 ( V_92 -> V_112 , 8 ) ;
}
}
free = V_8 -> V_43 - V_90 -> V_113 ;
V_6 = V_90 -> V_113 - V_94 ;
if ( free > V_8 -> V_43 || free < 0 || V_6 > V_8 -> V_43 ||
V_6 < 0 ) {
F_36 ( V_8 , L_23 ,
V_56 , free , V_6 ) ;
goto V_107;
}
if ( V_24 -> free + V_24 -> V_6 == V_8 -> V_43 &&
free + V_6 == V_8 -> V_43 )
if ( ( V_93 && ! ( V_24 -> V_25 & V_44 ) ) ||
( ! V_93 && free == V_8 -> V_43 ) ||
V_24 -> free == V_8 -> V_43 ) {
free = V_24 -> free ;
V_6 = V_24 -> V_6 ;
V_93 = 0 ;
}
if ( V_93 && V_24 -> free + V_24 -> V_6 == free + V_6 &&
V_56 != V_8 -> V_114 ) {
free = V_24 -> free ;
V_6 = V_24 -> V_6 ;
}
if ( V_24 -> free != free || V_24 -> V_6 != V_6 )
goto V_115;
if ( V_93 && ! ( V_24 -> V_25 & V_44 ) ) {
if ( free == V_8 -> V_43 )
V_93 = 0 ;
else {
F_36 ( V_8 , L_24 ) ;
goto V_115;
}
}
if ( ! V_93 && ( V_24 -> V_25 & V_44 ) ) {
F_36 ( V_8 , L_25 ) ;
goto V_115;
}
if ( free == V_8 -> V_43 )
V_63 -> V_64 += 1 ;
if ( V_93 )
V_63 -> V_74 += 1 ;
if ( ! ( V_24 -> V_25 & V_44 ) )
V_63 -> V_70 += V_8 -> V_43 - free - V_6 ;
V_63 -> V_66 += free ;
V_63 -> V_67 += V_6 ;
if ( ! ( V_24 -> V_25 & V_44 ) ) {
int V_50 = free + V_6 ;
if ( V_50 < V_8 -> V_46 )
V_63 -> V_68 += V_50 ;
else
V_63 -> V_69 += F_19 ( V_8 , V_50 ) ;
}
F_62 ( V_90 ) ;
F_63 ( V_96 ) ;
return V_101 ;
V_115:
F_36 ( V_8 , L_26 ,
V_56 , V_24 -> free , V_24 -> V_6 , V_24 -> V_25 , free , V_6 ) ;
F_64 ( V_8 , V_56 ) ;
V_107:
F_62 ( V_90 ) ;
V_95 = - V_85 ;
V_80:
F_63 ( V_96 ) ;
return V_95 ;
}
int F_65 ( struct V_7 * V_8 )
{
int V_84 , V_79 ;
struct V_76 V_63 ;
if ( ! F_47 ( V_8 ) )
return 0 ;
for ( V_84 = 0 ; V_84 < V_8 -> V_116 ; V_84 ++ ) {
V_79 = F_66 ( & V_8 -> V_117 [ V_84 ] . V_118 ) ;
if ( V_79 )
return V_79 ;
}
memset ( & V_63 , 0 , sizeof( struct V_76 ) ) ;
V_79 = F_67 ( V_8 , V_8 -> V_57 , V_8 -> V_119 - 1 ,
( V_120 ) F_52 ,
& V_63 ) ;
if ( V_79 && V_79 != - V_121 )
goto V_80;
if ( V_63 . V_64 != V_8 -> V_63 . V_64 ||
V_63 . V_74 != V_8 -> V_63 . V_74 ||
V_63 . V_66 != V_8 -> V_63 . V_66 ||
V_63 . V_67 != V_8 -> V_63 . V_67 ||
V_63 . V_70 != V_8 -> V_63 . V_70 ) {
F_36 ( V_8 , L_27 ) ;
F_36 ( V_8 , L_28 ,
V_63 . V_64 , V_63 . V_74 , V_63 . V_66 ,
V_63 . V_67 , V_63 . V_70 ) ;
F_36 ( V_8 , L_29 ,
V_8 -> V_63 . V_64 , V_8 -> V_63 . V_74 , V_8 -> V_63 . V_66 ,
V_8 -> V_63 . V_67 , V_8 -> V_63 . V_70 ) ;
V_79 = - V_85 ;
goto V_80;
}
if ( V_63 . V_68 != V_8 -> V_63 . V_68 ||
V_63 . V_69 != V_8 -> V_63 . V_69 ) {
F_36 ( V_8 , L_30 ) ;
F_36 ( V_8 , L_31 ,
V_63 . V_68 , V_63 . V_69 ) ;
F_36 ( V_8 , L_32 ,
V_8 -> V_63 . V_68 , V_8 -> V_63 . V_69 ) ;
V_79 = - V_85 ;
goto V_80;
}
V_79 = F_45 ( V_8 ) ;
V_80:
return V_79 ;
}
