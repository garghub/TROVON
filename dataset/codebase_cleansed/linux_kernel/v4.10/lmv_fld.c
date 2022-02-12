int lmv_fld_lookup(struct lmv_obd *lmv, const struct lu_fid *fid, u32 *mds)
{
struct obd_device *obd = lmv2obd_dev(lmv);
int rc;
if (!fid_is_sane(fid) || !(fid_seq_in_fldb(fid_seq(fid)) ||
fid_seq_is_local_file(fid_seq(fid)))) {
CERROR("%s: invalid FID " DFID "\n", obd->obd_name, PFID(fid));
return -EINVAL;
}
rc = fld_client_lookup(&lmv->lmv_fld, fid_seq(fid), mds,
LU_SEQ_RANGE_MDT, NULL);
if (rc) {
CERROR("Error while looking for mds number. Seq %#llx, err = %d\n",
fid_seq(fid), rc);
return rc;
}
CDEBUG(D_INODE, "FLD lookup got mds #%x for fid="DFID"\n",
*mds, PFID(fid));
if (*mds >= lmv->desc.ld_tgt_count) {
CERROR("FLD lookup got invalid mds #%x (max: %x) for fid=" DFID "\n", *mds, lmv->desc.ld_tgt_count,
PFID(fid));
rc = -EINVAL;
}
return rc;
}
