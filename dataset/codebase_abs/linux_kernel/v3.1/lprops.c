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
if ( V_2 -> V_25 & V_40 )
return V_27 ;
if ( V_2 -> free == V_8 -> V_41 ) {
F_5 ( ! ( V_2 -> V_25 & V_42 ) ) ;
return V_33 ;
}
if ( V_2 -> free + V_2 -> V_6 == V_8 -> V_41 ) {
if ( V_2 -> V_25 & V_42 )
return V_38 ;
else
return V_35 ;
}
if ( V_2 -> V_25 & V_42 ) {
if ( V_2 -> V_6 + V_2 -> free >= V_8 -> V_43 )
return V_5 ;
} else {
if ( V_2 -> V_6 >= V_8 -> V_44 &&
V_2 -> V_6 > V_2 -> free )
return V_32 ;
if ( V_2 -> free > 0 )
return V_4 ;
}
return V_27 ;
}
static void F_18 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
int V_45 = V_2 -> V_25 & V_26 ;
int V_46 = F_17 ( V_8 , V_2 ) ;
if ( V_45 == V_46 ) {
struct V_9 * V_10 = & V_8 -> V_19 [ V_46 - 1 ] ;
if ( V_46 < 1 || V_46 > V_47 )
return;
V_10 = & V_8 -> V_19 [ V_46 - 1 ] ;
F_3 ( V_8 , V_10 , V_2 , V_2 -> V_13 , V_46 ) ;
} else {
F_11 ( V_8 , V_2 , V_45 ) ;
F_10 ( V_8 , V_2 , V_46 ) ;
}
}
int F_19 ( const struct V_7 * V_8 , int V_48 )
{
F_5 ( ! ( V_48 & 7 ) ) ;
if ( V_48 < V_8 -> V_49 )
return V_48 ;
if ( V_48 - V_8 -> V_49 < V_50 )
return V_48 - V_50 ;
return V_8 -> V_49 ;
}
static int F_20 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_51 * V_52 ;
int V_53 ;
V_53 = ( V_2 -> V_54 - V_8 -> V_55 ) & ( V_56 - 1 ) ;
V_52 = (struct V_51 * ) F_21 ( V_2 - V_53 ,
struct V_51 ,
V_2 [ 0 ] ) ;
return ! F_22 ( V_57 , & V_52 -> V_25 ) &&
F_22 ( V_58 , & V_52 -> V_25 ) ;
}
const struct V_1 * F_23 ( struct V_7 * V_8 ,
const struct V_1 * V_24 ,
int free , int V_6 , int V_25 ,
int V_59 )
{
struct V_1 * V_2 = (struct V_1 * ) V_24 ;
F_24 ( L_1 ,
V_2 -> V_54 , free , V_6 , V_25 ) ;
F_5 ( F_25 ( & V_8 -> V_60 ) ) ;
F_5 ( V_8 -> V_61 . V_62 >= 0 &&
V_8 -> V_61 . V_62 <= V_8 -> V_63 ) ;
F_5 ( V_8 -> V_37 >= 0 ) ;
F_5 ( V_8 -> V_37 <= V_8 -> V_63 ) ;
F_5 ( V_8 -> V_61 . V_64 >= 0 ) ;
F_5 ( V_8 -> V_61 . V_64 <= V_8 -> V_61 . V_62 ) ;
F_5 ( ! ( V_8 -> V_61 . V_65 & 7 ) && ! ( V_8 -> V_61 . V_66 & 7 ) ) ;
F_5 ( ! ( V_8 -> V_61 . V_67 & 7 ) && ! ( V_8 -> V_61 . V_68 & 7 ) ) ;
F_5 ( ! ( V_8 -> V_61 . V_69 & 7 ) ) ;
F_5 ( free == V_70 || free >= 0 ) ;
F_5 ( V_6 == V_70 || V_6 >= 0 ) ;
if ( ! F_20 ( V_8 , V_2 ) ) {
V_2 = F_26 ( V_8 , V_2 -> V_54 ) ;
if ( F_27 ( V_2 ) )
return V_2 ;
} else
F_5 ( V_2 == F_26 ( V_8 , V_2 -> V_54 ) ) ;
F_5 ( ! ( V_2 -> free & 7 ) && ! ( V_2 -> V_6 & 7 ) ) ;
F_28 ( & V_8 -> V_71 ) ;
if ( ( V_2 -> V_25 & V_40 ) && V_2 -> free == V_8 -> V_41 )
V_8 -> V_61 . V_64 -= 1 ;
if ( ! ( V_2 -> V_25 & V_42 ) ) {
int V_72 ;
V_72 = V_2 -> free + V_2 -> V_6 ;
if ( V_72 < V_8 -> V_44 )
V_8 -> V_61 . V_67 -= V_72 ;
else
V_8 -> V_61 . V_68 -= F_19 ( V_8 , V_72 ) ;
V_8 -> V_61 . V_69 -= V_8 -> V_41 - V_72 ;
}
if ( free != V_70 ) {
free = F_29 ( free , 8 ) ;
V_8 -> V_61 . V_65 += free - V_2 -> free ;
if ( free == V_8 -> V_41 ) {
if ( V_2 -> free != V_8 -> V_41 )
V_8 -> V_61 . V_62 += 1 ;
} else if ( V_2 -> free == V_8 -> V_41 )
V_8 -> V_61 . V_62 -= 1 ;
V_2 -> free = free ;
}
if ( V_6 != V_70 ) {
V_6 = F_29 ( V_6 , 8 ) ;
V_8 -> V_61 . V_66 += V_6 - V_2 -> V_6 ;
V_2 -> V_6 = V_6 ;
}
if ( V_25 != V_70 ) {
if ( ( V_2 -> V_25 & V_42 ) ) {
if ( ! ( V_25 & V_42 ) )
V_8 -> V_61 . V_73 -= 1 ;
} else if ( V_25 & V_42 )
V_8 -> V_61 . V_73 += 1 ;
V_2 -> V_25 = V_25 ;
}
if ( ! ( V_2 -> V_25 & V_42 ) ) {
int V_74 ;
V_74 = V_2 -> free + V_2 -> V_6 ;
if ( V_74 < V_8 -> V_44 )
V_8 -> V_61 . V_67 += V_74 ;
else
V_8 -> V_61 . V_68 += F_19 ( V_8 , V_74 ) ;
V_8 -> V_61 . V_69 += V_8 -> V_41 - V_74 ;
}
if ( ( V_2 -> V_25 & V_40 ) && V_2 -> free == V_8 -> V_41 )
V_8 -> V_61 . V_64 += 1 ;
F_18 ( V_8 , V_2 ) ;
V_8 -> V_59 += V_59 ;
F_30 ( & V_8 -> V_71 ) ;
return V_2 ;
}
void F_31 ( struct V_7 * V_8 , struct V_75 * V_61 )
{
F_28 ( & V_8 -> V_71 ) ;
memcpy ( V_61 , & V_8 -> V_61 , sizeof( struct V_75 ) ) ;
F_30 ( & V_8 -> V_71 ) ;
}
int F_32 ( struct V_7 * V_8 , int V_54 , int free , int V_6 ,
int V_76 , int V_77 , int V_59 )
{
int V_78 = 0 , V_25 ;
const struct V_1 * V_24 ;
F_33 ( V_8 ) ;
V_24 = F_26 ( V_8 , V_54 ) ;
if ( F_27 ( V_24 ) ) {
V_78 = F_34 ( V_24 ) ;
goto V_79;
}
V_25 = ( V_24 -> V_25 | V_76 ) & ~ V_77 ;
V_24 = F_23 ( V_8 , V_24 , free , V_6 , V_25 , V_59 ) ;
if ( F_27 ( V_24 ) )
V_78 = F_34 ( V_24 ) ;
V_79:
F_35 ( V_8 ) ;
if ( V_78 )
F_36 ( L_2 ,
V_54 , V_78 ) ;
return V_78 ;
}
int F_37 ( struct V_7 * V_8 , int V_54 , int free , int V_6 ,
int V_76 , int V_77 )
{
int V_78 = 0 , V_25 ;
const struct V_1 * V_24 ;
F_33 ( V_8 ) ;
V_24 = F_26 ( V_8 , V_54 ) ;
if ( F_27 ( V_24 ) ) {
V_78 = F_34 ( V_24 ) ;
goto V_79;
}
V_25 = ( V_24 -> V_25 | V_76 ) & ~ V_77 ;
V_24 = F_23 ( V_8 , V_24 , free , V_24 -> V_6 + V_6 , V_25 , 0 ) ;
if ( F_27 ( V_24 ) )
V_78 = F_34 ( V_24 ) ;
V_79:
F_35 ( V_8 ) ;
if ( V_78 )
F_36 ( L_3 ,
V_54 , V_78 ) ;
return V_78 ;
}
int F_38 ( struct V_7 * V_8 , int V_54 , struct V_1 * V_24 )
{
int V_78 = 0 ;
const struct V_1 * V_80 ;
F_33 ( V_8 ) ;
V_80 = F_39 ( V_8 , V_54 ) ;
if ( F_27 ( V_80 ) ) {
V_78 = F_34 ( V_80 ) ;
F_36 ( L_4 ,
V_54 , V_78 ) ;
goto V_79;
}
memcpy ( V_24 , V_80 , sizeof( struct V_1 ) ) ;
V_79:
F_35 ( V_8 ) ;
return V_78 ;
}
const struct V_1 * F_40 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
F_5 ( F_25 ( & V_8 -> V_60 ) ) ;
V_10 = & V_8 -> V_19 [ V_4 - 1 ] ;
if ( V_10 -> V_18 == 0 )
return NULL ;
V_2 = V_10 -> V_15 [ 0 ] ;
F_5 ( ! ( V_2 -> V_25 & V_40 ) ) ;
F_5 ( ! ( V_2 -> V_25 & V_42 ) ) ;
return V_2 ;
}
const struct V_1 * F_41 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
F_5 ( F_25 ( & V_8 -> V_60 ) ) ;
if ( F_12 ( & V_8 -> V_34 ) )
return NULL ;
V_2 = F_42 ( V_8 -> V_34 . V_81 , struct V_1 , V_28 ) ;
F_5 ( ! ( V_2 -> V_25 & V_40 ) ) ;
F_5 ( ! ( V_2 -> V_25 & V_42 ) ) ;
F_5 ( V_2 -> free == V_8 -> V_41 ) ;
return V_2 ;
}
const struct V_1 * F_43 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
F_5 ( F_25 ( & V_8 -> V_60 ) ) ;
if ( F_12 ( & V_8 -> V_36 ) )
return NULL ;
V_2 = F_42 ( V_8 -> V_36 . V_81 , struct V_1 , V_28 ) ;
F_5 ( ! ( V_2 -> V_25 & V_40 ) ) ;
F_5 ( ! ( V_2 -> V_25 & V_42 ) ) ;
F_5 ( V_2 -> free + V_2 -> V_6 == V_8 -> V_41 ) ;
F_5 ( V_8 -> V_37 > 0 ) ;
return V_2 ;
}
const struct V_1 * F_44 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
F_5 ( F_25 ( & V_8 -> V_60 ) ) ;
if ( F_12 ( & V_8 -> V_39 ) )
return NULL ;
V_2 = F_42 ( V_8 -> V_39 . V_81 , struct V_1 , V_28 ) ;
F_5 ( ! ( V_2 -> V_25 & V_40 ) ) ;
F_5 ( ( V_2 -> V_25 & V_42 ) ) ;
F_5 ( V_2 -> free + V_2 -> V_6 == V_8 -> V_41 ) ;
return V_2 ;
}
int F_45 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
struct V_82 * V_53 ;
int V_83 , V_3 ;
if ( ! F_46 ( V_8 ) && ! F_47 ( V_8 ) )
return 0 ;
F_48 (lprops, &c->empty_list, list) {
if ( V_2 -> free != V_8 -> V_41 ) {
F_36 ( L_5
L_6 , V_2 -> V_54 ,
V_2 -> free , V_2 -> V_6 , V_2 -> V_25 ) ;
return - V_84 ;
}
if ( V_2 -> V_25 & V_40 ) {
F_36 ( L_7
L_6 , V_2 -> V_54 ,
V_2 -> free , V_2 -> V_6 , V_2 -> V_25 ) ;
return - V_84 ;
}
}
V_83 = 0 ;
F_48 (lprops, &c->freeable_list, list) {
if ( V_2 -> free + V_2 -> V_6 != V_8 -> V_41 ) {
F_36 ( L_8
L_6 , V_2 -> V_54 ,
V_2 -> free , V_2 -> V_6 , V_2 -> V_25 ) ;
return - V_84 ;
}
if ( V_2 -> V_25 & V_40 ) {
F_36 ( L_9
L_6 , V_2 -> V_54 ,
V_2 -> free , V_2 -> V_6 , V_2 -> V_25 ) ;
return - V_84 ;
}
V_83 += 1 ;
}
if ( V_83 != V_8 -> V_37 ) {
F_36 ( L_10 , V_83 ,
V_8 -> V_37 ) ;
return - V_84 ;
}
V_83 = 0 ;
F_49 (pos, &c->idx_gc)
V_83 += 1 ;
if ( V_83 != V_8 -> V_59 ) {
F_36 ( L_11 , V_83 ,
V_8 -> V_59 ) ;
return - V_84 ;
}
F_48 (lprops, &c->frdi_idx_list, list) {
if ( V_2 -> free + V_2 -> V_6 != V_8 -> V_41 ) {
F_36 ( L_12
L_6 , V_2 -> V_54 ,
V_2 -> free , V_2 -> V_6 , V_2 -> V_25 ) ;
return - V_84 ;
}
if ( V_2 -> V_25 & V_40 ) {
F_36 ( L_13
L_6 , V_2 -> V_54 ,
V_2 -> free , V_2 -> V_6 , V_2 -> V_25 ) ;
return - V_84 ;
}
if ( ! ( V_2 -> V_25 & V_42 ) ) {
F_36 ( L_14
L_6 , V_2 -> V_54 ,
V_2 -> free , V_2 -> V_6 , V_2 -> V_25 ) ;
return - V_84 ;
}
}
for ( V_3 = 1 ; V_3 <= V_47 ; V_3 ++ ) {
struct V_9 * V_10 = & V_8 -> V_19 [ V_3 - 1 ] ;
for ( V_83 = 0 ; V_83 < V_10 -> V_18 ; V_83 ++ ) {
V_2 = V_10 -> V_15 [ V_83 ] ;
if ( ! V_2 ) {
F_36 ( L_15 , V_3 ) ;
return - V_84 ;
}
if ( V_2 -> V_13 != V_83 ) {
F_36 ( L_16 , V_3 ) ;
return - V_84 ;
}
if ( V_2 -> V_25 & V_40 ) {
F_36 ( L_17 , V_3 ) ;
return - V_84 ;
}
}
}
return 0 ;
}
void F_7 ( struct V_7 * V_8 , struct V_9 * V_10 , int V_3 ,
int V_85 )
{
int V_83 = 0 , V_86 , V_78 = 0 ;
if ( ! F_46 ( V_8 ) && ! F_47 ( V_8 ) )
return;
for ( V_83 = 0 ; V_83 < V_10 -> V_18 ; V_83 ++ ) {
struct V_1 * V_2 = V_10 -> V_15 [ V_83 ] ;
struct V_1 * V_24 ;
if ( V_83 != V_85 )
if ( ( V_2 -> V_25 & V_26 ) != V_3 ) {
V_78 = 1 ;
goto V_79;
}
if ( V_2 -> V_13 != V_83 ) {
V_78 = 2 ;
goto V_79;
}
V_24 = F_39 ( V_8 , V_2 -> V_54 ) ;
if ( F_27 ( V_24 ) ) {
V_78 = 3 ;
goto V_79;
}
if ( V_2 != V_24 ) {
F_50 ( L_18 ,
( V_23 ) V_2 , ( V_23 ) V_24 , V_2 -> V_54 ,
V_24 -> V_54 ) ;
V_78 = 4 ;
goto V_79;
}
for ( V_86 = 0 ; V_86 < V_83 ; V_86 ++ ) {
V_24 = V_10 -> V_15 [ V_86 ] ;
if ( V_24 == V_2 ) {
V_78 = 5 ;
goto V_79;
}
if ( V_24 -> V_54 == V_2 -> V_54 ) {
V_78 = 6 ;
goto V_79;
}
}
}
V_79:
if ( V_78 ) {
F_50 ( L_19 , V_3 , V_83 , V_78 ) ;
F_51 () ;
F_52 ( V_8 , V_10 , V_3 ) ;
}
}
static int F_53 ( struct V_7 * V_8 ,
const struct V_1 * V_24 , int V_87 ,
struct V_75 * V_61 )
{
struct V_88 * V_89 ;
struct V_90 * V_91 ;
int V_3 , V_54 = V_24 -> V_54 , V_92 = 0 , V_93 = 0 , free , V_6 , V_94 ;
void * V_95 = NULL ;
V_3 = V_24 -> V_25 & V_26 ;
if ( V_3 != V_27 ) {
V_3 = F_17 ( V_8 , V_24 ) ;
if ( V_3 != ( V_24 -> V_25 & V_26 ) ) {
F_36 ( L_20 ,
( V_24 -> V_25 & V_26 ) , V_3 ) ;
return - V_84 ;
}
}
if ( V_87 ) {
struct V_82 * V_28 = NULL ;
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
int V_96 = 0 ;
F_48 (lprops, list, list) {
if ( V_2 == V_24 ) {
V_96 = 1 ;
break;
}
}
if ( ! V_96 ) {
F_36 ( L_21 , V_3 ) ;
return - V_84 ;
}
}
}
if ( V_87 && V_3 > 0 && V_3 <= V_47 ) {
struct V_9 * V_10 = & V_8 -> V_19 [ V_3 - 1 ] ;
if ( ( V_24 -> V_13 != - 1 && V_10 -> V_15 [ V_24 -> V_13 ] -> V_54 != V_54 ) ||
V_24 != V_10 -> V_15 [ V_24 -> V_13 ] ) {
F_36 ( L_22 , V_3 ) ;
return - V_84 ;
}
}
V_95 = F_54 ( V_8 -> V_41 , V_97 , V_98 ) ;
if ( ! V_95 )
return - V_99 ;
if ( V_24 -> free == V_8 -> V_41 ) {
V_61 -> V_62 += 1 ;
V_61 -> V_65 += V_8 -> V_41 ;
V_61 -> V_68 += F_19 ( V_8 , V_8 -> V_41 ) ;
return V_100 ;
}
if ( V_24 -> free + V_24 -> V_6 == V_8 -> V_41 &&
! ( V_24 -> V_25 & V_42 ) ) {
V_61 -> V_65 += V_24 -> free ;
V_61 -> V_66 += V_24 -> V_6 ;
V_61 -> V_68 += F_19 ( V_8 , V_8 -> V_41 ) ;
return V_100 ;
}
V_89 = F_55 ( V_8 , V_54 , 0 , V_95 , 0 ) ;
if ( F_27 ( V_89 ) ) {
V_94 = F_34 ( V_89 ) ;
if ( V_94 == - V_101 ) {
F_56 ( V_8 ) ;
F_57 ( V_8 , & V_8 -> V_102 ) ;
}
goto V_79;
}
V_92 = - 1 ;
F_48 (snod, &sleb->nodes, list) {
int V_96 , V_103 = 0 ;
F_58 () ;
if ( V_92 == - 1 )
V_92 = ( V_91 -> type == V_104 ) ? 1 : 0 ;
if ( V_92 && V_91 -> type != V_104 ) {
F_36 ( L_23 ,
V_54 , V_91 -> V_105 ) ;
goto V_106;
}
if ( V_91 -> type == V_104 ) {
struct V_107 * V_108 = V_91 -> V_109 ;
F_59 ( V_8 , F_60 ( V_8 , V_108 ) , & V_91 -> V_110 ) ;
V_103 = F_61 ( V_108 -> V_103 ) ;
}
V_96 = F_62 ( V_8 , & V_91 -> V_110 , V_103 , V_54 ,
V_91 -> V_105 , V_92 ) ;
if ( V_96 ) {
if ( V_96 < 0 )
goto V_106;
V_93 += F_29 ( V_91 -> V_111 , 8 ) ;
}
}
free = V_8 -> V_41 - V_89 -> V_112 ;
V_6 = V_89 -> V_112 - V_93 ;
if ( free > V_8 -> V_41 || free < 0 || V_6 > V_8 -> V_41 ||
V_6 < 0 ) {
F_36 ( L_24
L_25 , V_54 , free , V_6 ) ;
goto V_106;
}
if ( V_24 -> free + V_24 -> V_6 == V_8 -> V_41 &&
free + V_6 == V_8 -> V_41 )
if ( ( V_92 && ! ( V_24 -> V_25 & V_42 ) ) ||
( ! V_92 && free == V_8 -> V_41 ) ||
V_24 -> free == V_8 -> V_41 ) {
free = V_24 -> free ;
V_6 = V_24 -> V_6 ;
V_92 = 0 ;
}
if ( V_92 && V_24 -> free + V_24 -> V_6 == free + V_6 &&
V_54 != V_8 -> V_113 ) {
free = V_24 -> free ;
V_6 = V_24 -> V_6 ;
}
if ( V_24 -> free != free || V_24 -> V_6 != V_6 )
goto V_114;
if ( V_92 && ! ( V_24 -> V_25 & V_42 ) ) {
if ( free == V_8 -> V_41 )
V_92 = 0 ;
else {
F_36 ( L_26
L_27 ) ;
goto V_114;
}
}
if ( ! V_92 && ( V_24 -> V_25 & V_42 ) ) {
F_36 ( L_28 ) ;
goto V_114;
}
if ( free == V_8 -> V_41 )
V_61 -> V_62 += 1 ;
if ( V_92 )
V_61 -> V_73 += 1 ;
if ( ! ( V_24 -> V_25 & V_42 ) )
V_61 -> V_69 += V_8 -> V_41 - free - V_6 ;
V_61 -> V_65 += free ;
V_61 -> V_66 += V_6 ;
if ( ! ( V_24 -> V_25 & V_42 ) ) {
int V_48 = free + V_6 ;
if ( V_48 < V_8 -> V_44 )
V_61 -> V_67 += V_48 ;
else
V_61 -> V_68 += F_19 ( V_8 , V_48 ) ;
}
F_63 ( V_89 ) ;
F_64 ( V_95 ) ;
return V_100 ;
V_114:
F_36 ( L_29
L_30 ,
V_54 , V_24 -> free , V_24 -> V_6 , V_24 -> V_25 , free , V_6 ) ;
F_65 ( V_8 , V_54 ) ;
V_106:
F_63 ( V_89 ) ;
V_94 = - V_84 ;
V_79:
F_64 ( V_95 ) ;
return V_94 ;
}
int F_66 ( struct V_7 * V_8 )
{
int V_83 , V_78 ;
struct V_75 V_61 ;
if ( ! F_47 ( V_8 ) )
return 0 ;
for ( V_83 = 0 ; V_83 < V_8 -> V_115 ; V_83 ++ ) {
V_78 = F_67 ( & V_8 -> V_116 [ V_83 ] . V_117 ) ;
if ( V_78 )
return V_78 ;
}
memset ( & V_61 , 0 , sizeof( struct V_75 ) ) ;
V_78 = F_68 ( V_8 , V_8 -> V_55 , V_8 -> V_118 - 1 ,
( V_119 ) F_53 ,
& V_61 ) ;
if ( V_78 && V_78 != - V_120 )
goto V_79;
if ( V_61 . V_62 != V_8 -> V_61 . V_62 ||
V_61 . V_73 != V_8 -> V_61 . V_73 ||
V_61 . V_65 != V_8 -> V_61 . V_65 ||
V_61 . V_66 != V_8 -> V_61 . V_66 ||
V_61 . V_69 != V_8 -> V_61 . V_69 ) {
F_36 ( L_31 ) ;
F_36 ( L_32
L_33 ,
V_61 . V_62 , V_61 . V_73 , V_61 . V_65 ,
V_61 . V_66 , V_61 . V_69 ) ;
F_36 ( L_34
L_33 ,
V_8 -> V_61 . V_62 , V_8 -> V_61 . V_73 , V_8 -> V_61 . V_65 ,
V_8 -> V_61 . V_66 , V_8 -> V_61 . V_69 ) ;
V_78 = - V_84 ;
goto V_79;
}
if ( V_61 . V_67 != V_8 -> V_61 . V_67 ||
V_61 . V_68 != V_8 -> V_61 . V_68 ) {
F_36 ( L_35 ) ;
F_36 ( L_36 ,
V_61 . V_67 , V_61 . V_68 ) ;
F_36 ( L_37 ,
V_8 -> V_61 . V_67 , V_8 -> V_61 . V_68 ) ;
V_78 = - V_84 ;
goto V_79;
}
V_78 = F_45 ( V_8 ) ;
V_79:
return V_78 ;
}
